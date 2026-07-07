#import "PaxPoslink.h"

// Semi SDK
#import "POSLinkSemi.h"
#import "PLSemiTerminal.h"
#import "PLTransaction.h"
#import "PLBatch.h"
#import "PLReport.h"
#import "PLDoCreditRequest.h"
#import "PLDoCreditResponse.h"
#import "PLAmountRequest.h"
#import "PLAmountResponse.h"
#import "PLTraceRequest.h"
#import "PLTraceResponse.h"
#import "PLTransactionBehaviorRequest.h"
#import "PLAccountResponse.h"
#import "PLBatchCloseRequest.h"
#import "PLBatchCloseResponse.h"
#import "PLHistoryReportRequest.h"
#import "PLHistoryReportResponse.h"
#import "PLLocalDetailReportRequest.h"
#import "PLLocalDetailReportResponse.h"
#import "PLLocalTotalReportRequest.h"
#import "PLLocalTotalReportResponse.h"
#import "PLTotals.h"
#import "PLCreditTotals.h"
#import "PLDebitTotals.h"
#import "PLPaymentTransactionInformation.h"
#import "PLPaymentEmvTag.h"
#import "PLHostInformationResponse.h"
#import "PLTotalCount.h"
#import "PLTotalAmount.h"
#import "PLEdcTotalCount.h"
#import "PLEdcTotalAmount.h"
#import "PLTorResponse.h"
#import "PLSemiConst.h"

// Admin SDK
#import "PLAdminConst.h"
#import "PLBaseTerminal.h"
#import "PLCommunicationSetting.h"
#import "PLManage.h"
#import "PLInitRequest.h"
#import "PLInitResponse.h"
#import "PLExecutionResult.h"

// Bluetooth scan (Admin SDK) + CoreBluetooth để đọc trạng thái bật/tắt của adapter.
#import "MposBluetoothScan.h"
#import <CoreBluetooth/CoreBluetooth.h>

static PLSemiTerminal *_terminal = nil;
static NSDictionary *_lastSnInfo = nil;

// Trạng thái quét Bluetooth (mô hình poll giống Android: quét nền, gom vào dict theo
// address để dedupe; UI poll getBluetoothDeviceList rồi gọi stopBluetoothSearch khi đóng).
static NSMutableDictionary<NSString *, NSDictionary *> *_btDevices = nil;
static NSLock *_btLock = nil;
static BOOL _btScanning = NO;

#pragma mark - Bluetooth adapter state helper

@interface PaxBtStateHelper : NSObject <CBCentralManagerDelegate>
@property (nonatomic, strong) CBCentralManager *central;
@property (nonatomic, strong) NSMutableArray<void (^)(BOOL)> *pending;
@property (nonatomic, strong) NSLock *lock;
+ (instancetype)shared;
- (void)resolveEnabled:(void (^)(BOOL enabled))cb;
@end

@implementation PaxBtStateHelper

+ (instancetype)shared {
    static PaxBtStateHelper *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[PaxBtStateHelper alloc] init];
    });
    return instance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _pending = [NSMutableArray new];
        _lock = [NSLock new];
        // Tạo trên main queue để delegate fire ổn định.
        dispatch_async(dispatch_get_main_queue(), ^{
            self.central = [[CBCentralManager alloc] initWithDelegate:self queue:dispatch_get_main_queue()];
        });
    }
    return self;
}

- (BOOL)isPoweredOn {
    return self.central != nil && self.central.state == CBManagerStatePoweredOn;
}

- (void)resolveEnabled:(void (^)(BOOL))cb {
    if (cb == nil) return;
    dispatch_async(dispatch_get_main_queue(), ^{
        // State đã xác định → trả lời ngay.
        if (self.central != nil && self.central.state != CBManagerStateUnknown) {
            cb([self isPoweredOn]);
            return;
        }
        // Chưa xác định → xếp hàng chờ delegate, kèm timeout an toàn 4s tránh treo.
        [self.lock lock];
        [self.pending addObject:[cb copy]];
        [self.lock unlock];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(4.0 * NSEC_PER_SEC)),
                       dispatch_get_main_queue(), ^{
            [self flushWith:[self isPoweredOn]];
        });
    });
}

- (void)flushWith:(BOOL)enabled {
    [self.lock lock];
    NSArray<void (^)(BOOL)> *cbs = [self.pending copy];
    [self.pending removeAllObjects];
    [self.lock unlock];
    for (void (^cb)(BOOL) in cbs) {
        cb(enabled);
    }
}

- (void)centralManagerDidUpdateState:(CBCentralManager *)central {
    [self flushWith:(central.state == CBManagerStatePoweredOn)];
}

@end

@implementation PaxPoslink

RCT_EXPORT_MODULE(PaxPoslink)

+ (void)initialize
{
    if (self == [PaxPoslink class]) {
        _btDevices = [NSMutableDictionary new];
        _btLock = [NSLock new];
    }
}

+ (BOOL)requiresMainQueueSetup
{
    return NO;
}

#pragma mark - initPOSLink

- (void)initPOSLink:(NSString *)ip
               port:(NSString *)port
            timeout:(NSNumber *)timeout
            resolve:(RCTPromiseResolveBlock)resolve
             reject:(RCTPromiseRejectBlock)reject
{
    PLCommunicationSetting *comm = [[PLCommunicationSetting alloc] init];
    comm.communicationType = CommunicationTypeTCP;
    comm.destIP = ip ?: @"";
    comm.destPort = (port && port.length > 0) ? port : @"10009";
    comm.timeout = timeout ? [NSString stringWithFormat:@"%d", timeout.intValue] : @"60000";

    NSString *info = [NSString stringWithFormat:@"type=TCP, ip=%@, port=%@, timeout=%@",
                      comm.destIP, comm.destPort, comm.timeout];
    [self connectWithCommSetting:comm info:info resolve:resolve reject:reject];
}

#pragma mark - initPOSLinkConn (mọi kiểu giao tiếp iOS hỗ trợ)

/**
 * Kết nối tới terminal theo kiểu giao tiếp trong config (mirror Android initPOSLinkConn).
 *
 * iOS SDK chỉ hỗ trợ: TCP, SSL, HTTP, HTTPS, BLUETOOTH.
 * Các kiểu chỉ có trên Android (UART, USB, AIDL) sẽ bị reject UNSUPPORTED_CONN_TYPE.
 *  - TCP/SSL/HTTP/HTTPS : cần ip, port (mặc định 10009).
 *  - BLUETOOTH          : cần macAddr (UUID/MAC lấy từ startBluetoothSearch).
 */
- (void)performInitConnWithConfig:(NSDictionary *)config
                          resolve:(RCTPromiseResolveBlock)resolve
                           reject:(RCTPromiseRejectBlock)reject
{
    NSString *type = [([config[@"type"] isKindOfClass:[NSString class]] ? config[@"type"] : @"TCP") uppercaseString];
    NSNumber *timeoutNum = [config[@"timeout"] isKindOfClass:[NSNumber class]] ? config[@"timeout"] : nil;
    NSString *timeout = timeoutNum ? [NSString stringWithFormat:@"%d", timeoutNum.intValue] : @"60000";
    NSString *ip = [config[@"ip"] isKindOfClass:[NSString class]] ? config[@"ip"] : @"";
    NSString *port = ([config[@"port"] isKindOfClass:[NSString class]] && [config[@"port"] length] > 0)
        ? config[@"port"] : @"10009";

    PLCommunicationSetting *comm = [[PLCommunicationSetting alloc] init];
    comm.timeout = timeout;
    NSString *info;

    if ([type isEqualToString:@"TCP"]) {
        comm.communicationType = CommunicationTypeTCP;
        comm.destIP = ip; comm.destPort = port;
        info = [NSString stringWithFormat:@"type=TCP, ip=%@, port=%@, timeout=%@", ip, port, timeout];
    } else if ([type isEqualToString:@"SSL"]) {
        comm.communicationType = CommunicationTypeSSL;
        comm.destIP = ip; comm.destPort = port;
        info = [NSString stringWithFormat:@"type=SSL, ip=%@, port=%@, timeout=%@", ip, port, timeout];
    } else if ([type isEqualToString:@"HTTP"]) {
        comm.communicationType = CommunicationTypeHTTP;
        comm.destIP = ip; comm.destPort = port;
        info = [NSString stringWithFormat:@"type=HTTP, ip=%@, port=%@, timeout=%@", ip, port, timeout];
    } else if ([type isEqualToString:@"HTTPS"]) {
        comm.communicationType = CommunicationTypeHTTPS;
        comm.destIP = ip; comm.destPort = port;
        info = [NSString stringWithFormat:@"type=HTTPS, ip=%@, port=%@, timeout=%@", ip, port, timeout];
    } else if ([type isEqualToString:@"BLUETOOTH"] || [type isEqualToString:@"BLE"]) {
        NSString *macAddr = [config[@"macAddr"] isKindOfClass:[NSString class]] ? config[@"macAddr"] : @"";
        comm.communicationType = CommunicationTypeBLUETOOTH;
        comm.bluetoothAddr = macAddr;
        info = [NSString stringWithFormat:@"type=BLUETOOTH, macAddr=%@, timeout=%@", macAddr, timeout];
    } else {
        // UART / USB / AIDL: không khả dụng trên iOS.
        reject(@"UNSUPPORTED_CONN_TYPE",
               [NSString stringWithFormat:@"Connection type '%@' is not supported on iOS (only TCP/SSL/HTTP/HTTPS/BLUETOOTH).", type],
               nil);
        return;
    }

    [self connectWithCommSetting:comm info:info resolve:resolve reject:reject];
}

#ifdef RCT_NEW_ARCH_ENABLED
- (void)initPOSLinkConn:(JS::NativePaxPoslink::SpecInitPOSLinkConnConfig &)config
                resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject
{
    @try {
        NSMutableDictionary *cfg = [NSMutableDictionary new];
        cfg[@"type"] = config.type() ?: @"TCP";
        if (config.ip() != nil) cfg[@"ip"] = config.ip();
        if (config.port() != nil) cfg[@"port"] = config.port();
        if (config.serialPort() != nil) cfg[@"serialPort"] = config.serialPort();
        if (config.baudRate() != nil) cfg[@"baudRate"] = config.baudRate();
        if (config.deviceName() != nil) cfg[@"deviceName"] = config.deviceName();
        if (config.macAddr() != nil) cfg[@"macAddr"] = config.macAddr();
        if (config.timeout().has_value()) cfg[@"timeout"] = @(config.timeout().value());
        [self performInitConnWithConfig:cfg resolve:resolve reject:reject];
    } @catch (NSException *e) {
        reject(@"INIT_ERROR", e.reason ?: @"Init connection error", nil);
    }
}
#endif

/** Luồng kết nối chung: getTerminal → init() round-trip → resolve thông tin terminal. */
- (void)connectWithCommSetting:(PLCommunicationSetting *)comm
                          info:(NSString *)info
                       resolve:(RCTPromiseResolveBlock)resolve
                        reject:(RCTPromiseRejectBlock)reject
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @try {
            PLSemiTerminal *terminal = [[POSLinkSemi getInstance]
                                        getTerminalWithCommunicationSetting:comm];
            if (terminal == nil) {
                reject(@"CONNECT_FAILED",
                       @"Could not connect to terminal. Check connection settings.",
                       nil);
                return;
            }
            _terminal = terminal;

            PLInitRequest *initReq = [[PLInitRequest alloc] init];
            [[terminal getManage] initWithRequest:initReq
                                       completion:^(PLInitResponse *rsp, PLExecutionResult *result) {
                if (rsp == nil || rsp.sn.length == 0) {
                    // Lộ lý do thật giống Android: code + msg từ terminal/SDK, thay vì che bằng câu generic.
                    NSString *code = (rsp.responseCode.length > 0) ? rsp.responseCode : @"NO_RESPONSE";
                    NSString *msg = (rsp.responseMessage.length > 0)
                        ? rsp.responseMessage
                        : (result.responseMessage ?: @"");
                    NSString *detail = (msg.length > 0)
                        ? [NSString stringWithFormat:@"(code=%@, msg=%@)", code, msg]
                        : [NSString stringWithFormat:@"(code=%@)", code];
                    reject(@"CONNECT_FAILED",
                           [NSString stringWithFormat:@"Terminal did not respond to init %@. Check IP/port and Semi-Integration mode.", detail],
                           nil);
                    return;
                }
                NSString *sn = rsp.sn ?: @"";
                NSString *model = rsp.modelName ?: @"";
                NSDictionary *snInfo = @{
                    @"serialNumber": sn,
                    @"modelName": model,
                    @"appName": rsp.appName ?: @""
                };
                _lastSnInfo = snInfo;
                // Message dễ đọc kèm SN/model terminal vừa kết nối (thay cho chuỗi debug type/ip/port).
                NSString *message = (model.length > 0)
                    ? [NSString stringWithFormat:@"Connected to terminal successfully (SN: %@, model: %@)", sn, model]
                    : [NSString stringWithFormat:@"Connected to terminal successfully (SN: %@)", sn];
                NSMutableDictionary *map = [NSMutableDictionary new];
                [map setObject:@YES forKey:@"status"];
                [map setObject:message forKey:@"message"];
                [map setObject:@YES forKey:@"isPaymentSuccess"];
                [map setObject:snInfo forKey:@"serialNumber"];
                resolve(map);
            }];
        } @catch (NSException *e) {
            reject(@"INIT_ERROR", [NSString stringWithFormat:@"%@ (%@)", e.reason ?: @"Unknown error", info], nil);
        }
    });
}

#pragma mark - USB / Serial / Baud (không khả dụng trên iOS — trả rỗng để parity với Android)

/** iOS không có USB host API như Android → luôn resolve false (không có thiết bị/không cần quyền). */
- (void)requestUsbPermission:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject
{
    resolve(@NO);
}

/** iOS không liệt kê thiết bị USB → trả mảng rỗng. */
- (void)listUsbDevices:(RCTPromiseResolveBlock)resolve
                reject:(RCTPromiseRejectBlock)reject
{
    resolve(@[]);
}

/** iOS không hỗ trợ UART → không có baud rate. */
- (void)getSupportedBaudRates:(RCTPromiseResolveBlock)resolve
                       reject:(RCTPromiseRejectBlock)reject
{
    resolve(@[]);
}

/** iOS không có cổng serial → trả mảng rỗng. */
- (void)listSerialPorts:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject
{
    resolve(@[]);
}

#pragma mark - Bluetooth

/** Kiểm tra Bluetooth đã bật chưa (CoreBluetooth poweredOn). */
- (void)checkBluetoothEnable:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject
{
    [[PaxBtStateHelper shared] resolveEnabled:^(BOOL enabled) {
        resolve(@(enabled));
    }];
}

/**
 * Bắt đầu quét Bluetooth (MposBluetoothScan — giống demo POSLinkPluginBtSearch).
 * Kết quả gom vào dict nội bộ (dedupe theo address); UI poll getBluetoothDeviceList.
 * @param useBle YES bật cập nhật RSSI (chỉ áp dụng BLE).
 * @param timeout thời lượng quét (ms, đồng bộ với Android). iOS dùng giây nên đổi ms→s,
 *        tối thiểu 1s; <=0 dùng mặc định 60s.
 */
- (void)startBluetoothSearch:(BOOL)useBle
                     timeout:(double)timeout
                     resolve:(RCTPromiseResolveBlock)resolve
                      reject:(RCTPromiseRejectBlock)reject
{
    @try {
        [_btLock lock];
        [_btDevices removeAllObjects];
        _btScanning = YES;
        [_btLock unlock];

        NSInteger scanSeconds = timeout > 0 ? MAX(1, (NSInteger)(timeout / 1000.0)) : 60;

        dispatch_async(dispatch_get_main_queue(), ^{
            [[MposBluetoothScan sharedInstance] startWithTimeout:scanSeconds
                                                   didDiscovered:^(BtDevice *device) {
                if (device == nil || device.address.length == 0) return;
                NSDictionary *entry = @{
                    @"name": device.name ?: @"",
                    @"mac": device.address ?: @"",
                    @"rssi": @(device.RSSI)
                };
                [_btLock lock];
                _btDevices[device.address] = entry;
                [_btLock unlock];
            } didFinished:^{
                [_btLock lock];
                _btScanning = NO;
                [_btLock unlock];
            } needUpdateRSSI:useBle];
        });
        resolve(@YES);
    } @catch (NSException *e) {
        reject(@"BT_SEARCH_ERROR", e.reason ?: @"Bluetooth search error", nil);
    }
}

/** Dừng quét Bluetooth và xoá list nội bộ. */
- (void)stopBluetoothSearch:(RCTPromiseResolveBlock)resolve
                     reject:(RCTPromiseRejectBlock)reject
{
    @try {
        dispatch_async(dispatch_get_main_queue(), ^{
            [[MposBluetoothScan sharedInstance] stop];
        });
        [_btLock lock];
        [_btDevices removeAllObjects];
        _btScanning = NO;
        [_btLock unlock];
        resolve(@YES);
    } @catch (NSException *e) {
        reject(@"BT_STOP_ERROR", e.reason ?: @"Bluetooth stop error", nil);
    }
}

/** Trả list thiết bị Bluetooth đã phát hiện: [{ name, mac, rssi }]. */
- (void)getBluetoothDeviceList:(RCTPromiseResolveBlock)resolve
                        reject:(RCTPromiseRejectBlock)reject
{
    @try {
        [_btLock lock];
        NSArray *list = [_btDevices allValues];
        [_btLock unlock];
        resolve(list ?: @[]);
    } @catch (NSException *e) {
        reject(@"BT_LIST_ERROR", e.reason ?: @"Bluetooth list error", nil);
    }
}

#pragma mark - payment

- (void)performPaymentWithData:(NSDictionary *)data
                       resolve:(RCTPromiseResolveBlock)resolve
                        reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }

    NSNumber *paymentType = data[@"paymentType"];
    if (paymentType == nil) {
        reject(@"INVALID_TYPE", @"Please select transaction command (credit/debit)", nil);
        return;
    }

    @try {
        PLDoCreditRequest *req = [self buildCreditRequest:data transType:TransactionTypeSale];
        [[_terminal getTransaction] doCreditWithRequest:req
                                            completion:^(PLDoCreditResponse *rsp, PLExecutionResult *result) {
            resolve([self buildTransactionResponse:rsp result:result data:data]);
        }];
    } @catch (NSException *e) {
        reject(@"PAYMENT_ERROR", e.reason ?: @"Payment error", nil);
    }
}

#ifdef RCT_NEW_ARCH_ENABLED
- (void)payment:(JS::NativePaxPoslink::SpecPaymentData &)specData
         resolve:(RCTPromiseResolveBlock)resolve
          reject:(RCTPromiseRejectBlock)reject
{
    @try {
        NSMutableDictionary *data = [NSMutableDictionary new];
        if (specData.transactionId() != nil) data[@"transactionId"] = specData.transactionId();
        if (specData.amount().has_value()) data[@"amount"] = @(specData.amount().value());
        if (specData.tip().has_value()) data[@"tip"] = @(specData.tip().value());
        data[@"paymentType"] = @((int)specData.paymentType().value());
        if (specData.ecrRefNum() != nil) data[@"ecrRefNum"] = specData.ecrRefNum();
        if (specData.showTip().has_value()) data[@"showTip"] = @((BOOL)specData.showTip().value());
        [self performPaymentWithData:data resolve:resolve reject:reject];
    } @catch (NSException *e) {
        reject(@"PAYMENT_ERROR", e.reason ?: @"Payment error", nil);
    }
}
#endif

#pragma mark - refund

- (void)performRefundWithData:(NSDictionary *)data
                      resolve:(RCTPromiseResolveBlock)resolve
                       reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }
    @try {
        PLDoCreditRequest *req = [self buildCreditRequest:data transType:TransactionTypeReturn];
        [[_terminal getTransaction] doCreditWithRequest:req
                                            completion:^(PLDoCreditResponse *rsp, PLExecutionResult *result) {
            resolve([self buildTransactionResponse:rsp result:result data:data]);
        }];
    } @catch (NSException *e) {
        reject(@"REFUND_ERROR", e.reason ?: @"Refund error", nil);
    }
}

#ifdef RCT_NEW_ARCH_ENABLED
- (void)refund:(JS::NativePaxPoslink::SpecRefundData &)specData
        resolve:(RCTPromiseResolveBlock)resolve
         reject:(RCTPromiseRejectBlock)reject
{
    @try {
        NSDictionary *data = @{
            @"amount": @(specData.amount()),
            @"ecrRefNum": specData.ecrRefNum() ?: @""
        };
        [self performRefundWithData:data resolve:resolve reject:reject];
    } @catch (NSException *e) {
        reject(@"REFUND_ERROR", e.reason ?: @"Refund error", nil);
    }
}
#endif

#pragma mark - void

- (void)performVoidTransactionWithData:(NSDictionary *)data
                               resolve:(RCTPromiseResolveBlock)resolve
                                reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }
    @try {
        PLDoCreditRequest *req = [self buildCreditRequest:data transType:TransactionTypeVoidSale];
        [[_terminal getTransaction] doCreditWithRequest:req
                                            completion:^(PLDoCreditResponse *rsp, PLExecutionResult *result) {
            resolve([self buildTransactionResponse:rsp result:result data:data]);
        }];
    } @catch (NSException *e) {
        reject(@"VOID_ERROR", e.reason ?: @"Void transaction error", nil);
    }
}

#ifdef RCT_NEW_ARCH_ENABLED
- (void)voidTransaction:(JS::NativePaxPoslink::SpecVoidTransactionData &)specData
       resolve:(RCTPromiseResolveBlock)resolve
        reject:(RCTPromiseRejectBlock)reject
{
    @try {
        NSDictionary *data = @{
            @"ecrRefNum": specData.ecrRefNum() ?: @""
        };
        [self performVoidTransactionWithData:data resolve:resolve reject:reject];
    } @catch (NSException *e) {
        reject(@"VOID_ERROR", e.reason ?: @"Void transaction error", nil);
    }
}
#endif

#pragma mark - batchCloseout

- (void)batchCloseout:(RCTPromiseResolveBlock)resolve
               reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }
    @try {
        PLBatchCloseRequest *req = [[PLBatchCloseRequest alloc] init];
        [[_terminal getBatch] batchCloseWithRequest:req
                                         completion:^(PLBatchCloseResponse *rsp, PLExecutionResult *result) {
            NSMutableDictionary *map = [NSMutableDictionary new];
            if (result.isSuccessful) {
                [map setObject:@YES forKey:@"status"];
                [map setObject:@YES forKey:@"isPaymentSuccess"];
                [map setObject:rsp.responseMessage ?: @"Batch close successfully" forKey:@"message"];
                [map setObject:rsp.hostInformation.batchNumber ?: @"" forKey:@"refNum"];
                [map setObject:rsp.timeStamp ?: @"" forKey:@"transactionDateTime"];
                [map setObject:[self buildBatchCloseMap:rsp] forKey:@"data"];
            } else {
                [map setObject:@NO forKey:@"status"];
                [map setObject:@NO forKey:@"isPaymentSuccess"];
                [map setObject:result.responseMessage ?: rsp.responseMessage ?: @"Batch close error"
                        forKey:@"message"];
            }
            if (_lastSnInfo) [map setObject:_lastSnInfo forKey:@"sn"];
            [self applyRawCodes:map
                         result:result
                   responseCode:rsp.responseCode
                responseMessage:rsp.responseMessage
                           host:rsp.hostInformation];
            resolve(map);
        }];
    } @catch (NSException *e) {
        reject(@"BATCH_CLOSE_ERROR", e.reason ?: @"Batch close error", nil);
    }
}

#pragma mark - getBatchInformation

- (void)getBatchInformation:(RCTPromiseResolveBlock)resolve
                     reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }
    @try {
        PLReport *report = [_terminal getReport];
        PLHistoryReportRequest *req = [[PLHistoryReportRequest alloc] init];
        [report historyReportWithRequest:req
                              completion:^(PLHistoryReportResponse *histRsp, PLExecutionResult *histResult) {
            if (!histResult.isSuccessful) {
                reject(@"GET_BATCH_INFORMATION_FAILED",
                       histResult.responseMessage ?: @"Failed to get batch info", nil);
                return;
            }
            // Mirror Android getBatchInformation: bổ sung ecrReferenceNumber/totalRecord (localDetailReport)
            // và totalAmount (localTotalReport). iOS gọi bất đồng bộ nên phải lồng completion tuần tự.
            PLLocalDetailReportRequest *detailReq = [[PLLocalDetailReportRequest alloc] init];
            detailReq.edcType = EdcTypeAll;
            [report localDetailReportWithRequest:detailReq
                                      completion:^(PLLocalDetailReportResponse *detailRsp, PLExecutionResult *detailResult) {
                NSInteger ecrRef = 0, totalRecord = 0;
                if (detailResult.isSuccessful) {
                    ecrRef = [detailRsp.traceInformation.ecrReferenceNumber integerValue];
                    totalRecord = [detailRsp.totalRecord integerValue];
                }
                PLLocalTotalReportRequest *totalReq = [[PLLocalTotalReportRequest alloc] init];
                totalReq.edcType = EdcTypeAll;
                [report localTotalReportWithRequest:totalReq
                                         completion:^(PLLocalTotalReportResponse *totalRsp, PLExecutionResult *totalResult) {
                    NSInteger totalAmount = 0;
                    if (totalResult.isSuccessful && totalRsp.totals) {
                        PLCreditTotals *c = totalRsp.totals.creditTotals;
                        PLDebitTotals *d = totalRsp.totals.debitTotals;
                        NSInteger creditNet = [c.saleAmount integerValue] - [c.returnAmount integerValue];
                        NSInteger debitNet  = [d.saleAmount integerValue] - [d.returnAmount integerValue];
                        totalAmount = creditNet + debitNet;
                    }
                    NSMutableDictionary *map = [NSMutableDictionary new];
                    [map setObject:@YES forKey:@"status"];
                    [map setObject:@(ecrRef) forKey:@"ecrReferenceNumber"];
                    [map setObject:@(totalRecord) forKey:@"totalRecord"];
                    [map setObject:@(totalAmount) forKey:@"totalAmount"];
                    [map setObject:histRsp.responseMessage ?: @"Success" forKey:@"message"];
                    [map setObject:[self buildHistoryReportMap:histRsp] forKey:@"data"];
                    resolve(map);
                }];
            }];
        }];
    } @catch (NSException *e) {
        reject(@"GET_BATCH_INFORMATION_ERROR", e.reason ?: @"Get batch information error", nil);
    }
}

#pragma mark - checkVoidOrRefundTransaction

- (void)checkVoidOrRefundTransaction:(NSString *)ecrRefNum
                              resolve:(RCTPromiseResolveBlock)resolve
                               reject:(RCTPromiseRejectBlock)reject
{
    if (_terminal == nil) {
        reject(@"NO_TERMINAL", @"Please connect PAX terminal first", nil);
        return;
    }
    @try {
        PLLocalDetailReportRequest *req = [[PLLocalDetailReportRequest alloc] init];
        req.ecrReferenceNumber = ecrRefNum;
        req.edcType = EdcTypeAll;
        [[_terminal getReport] localDetailReportWithRequest:req
                                                 completion:^(PLLocalDetailReportResponse *rsp, PLExecutionResult *result) {
            NSMutableDictionary *map = [NSMutableDictionary new];
            [map setObject:result.isSuccessful ? @"true" : @"false" forKey:@"code"];
            [map setObject:result.responseMessage ?: @"" forKey:@"message"];
            [map setObject:rsp.responseMessage ?: @"" forKey:@"status"];
            if (_lastSnInfo) [map setObject:_lastSnInfo forKey:@"serialNumber"];
            resolve(map);
        }];
    } @catch (NSException *e) {
        reject(@"CHECK_TRANSACTION_ERROR", e.reason ?: @"Check void or refund error", nil);
    }
}

#pragma mark - cancelTransaction

- (void)cancelTransaction:(RCTPromiseResolveBlock)resolve
            reject:(RCTPromiseRejectBlock)reject
{
    @try {
        if (_terminal != nil) {
            NSError *error;
            [_terminal cancelWithError:&error];
        }
        resolve(@"Cancel transaction requested");
    } @catch (NSException *e) {
        reject(@"CANCEL_ERROR", e.reason ?: @"Cancel transaction error", nil);
    }
}

#pragma mark - Private helpers

#ifndef RCT_NEW_ARCH_ENABLED
RCT_REMAP_METHOD(initPOSLink,
                 initPOSLinkWithIp:(NSString *)ip
                 port:(NSString *)port
                 timeout:(nonnull NSNumber *)timeout
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self initPOSLink:ip port:port timeout:timeout resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(payment,
                 paymentWithData:(NSDictionary *)data
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self performPaymentWithData:data resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(refund,
                 refundWithData:(NSDictionary *)data
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self performRefundWithData:data resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(voidTransaction,
                 voidTransactionWithData:(NSDictionary *)data
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self performVoidTransactionWithData:data resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(batchCloseout,
                 batchCloseoutWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self batchCloseout:resolve reject:reject];
}

RCT_REMAP_METHOD(getBatchInformation,
                 getBatchInformationWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self getBatchInformation:resolve reject:reject];
}

RCT_REMAP_METHOD(checkVoidOrRefundTransaction,
                 checkVoidOrRefundTransactionWithEcrRefNum:(NSString *)ecrRefNum
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self checkVoidOrRefundTransaction:ecrRefNum resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(cancelTransaction,
                 cancelTransactionWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self cancelTransaction:resolve reject:reject];
}

RCT_REMAP_METHOD(initPOSLinkConn,
                 initPOSLinkConnWithConfig:(NSDictionary *)config
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self performInitConnWithConfig:config resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(requestUsbPermission,
                 requestUsbPermissionWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self requestUsbPermission:resolve reject:reject];
}

RCT_REMAP_METHOD(listUsbDevices,
                 listUsbDevicesWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self listUsbDevices:resolve reject:reject];
}

RCT_REMAP_METHOD(getSupportedBaudRates,
                 getSupportedBaudRatesWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self getSupportedBaudRates:resolve reject:reject];
}

RCT_REMAP_METHOD(listSerialPorts,
                 listSerialPortsWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self listSerialPorts:resolve reject:reject];
}

RCT_REMAP_METHOD(checkBluetoothEnable,
                 checkBluetoothEnableWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self checkBluetoothEnable:resolve reject:reject];
}

RCT_REMAP_METHOD(startBluetoothSearch,
                 startBluetoothSearchWithUseBle:(BOOL)useBle
                 timeout:(double)timeout
                 resolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self startBluetoothSearch:useBle timeout:timeout resolve:resolve reject:reject];
}

RCT_REMAP_METHOD(stopBluetoothSearch,
                 stopBluetoothSearchWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self stopBluetoothSearch:resolve reject:reject];
}

RCT_REMAP_METHOD(getBluetoothDeviceList,
                 getBluetoothDeviceListWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self getBluetoothDeviceList:resolve reject:reject];
}
#endif

- (PLDoCreditRequest *)buildCreditRequest:(NSDictionary *)data
                                transType:(enum TransactionType)transType
{
    NSString *ecrRefNum = data[@"ecrRefNum"];
    NSNumber *amountNum = data[@"amount"];
    NSNumber *tipNum = data[@"tip"];
    id showTipRaw = data[@"showTip"];
    BOOL showTip = [showTipRaw isKindOfClass:[NSNumber class]]
        ? ((NSNumber *)showTipRaw).boolValue : NO;

    PLDoCreditRequest *req = [[PLDoCreditRequest alloc] init];
    req.transactionType = transType;

    PLAmountRequest *amountReq = [[PLAmountRequest alloc] init];
    amountReq.transactionAmount = amountNum
        ? [NSString stringWithFormat:@"%d", amountNum.intValue] : @"0";
    if (tipNum != nil) {
        amountReq.tipAmount = [NSString stringWithFormat:@"%d", tipNum.intValue];
    }
    req.amountInformation = amountReq;

    PLTraceRequest *traceReq = [[PLTraceRequest alloc] init];
    if (ecrRefNum.length > 0) {
        BOOL isSaleVoidReturn = (transType == TransactionTypeSale
                                 || transType == TransactionTypeVoidSale
                                 || transType == TransactionTypeReturn);
        if (isSaleVoidReturn) {
            traceReq.ecrReferenceNumber = ecrRefNum;
        }
        if (transType == TransactionTypeVoidSale) {
            traceReq.originalEcrReferenceNumber = ecrRefNum;
        }
    }
    req.traceInformation = traceReq;

    PLTransactionBehaviorRequest *behavior = [[PLTransactionBehaviorRequest alloc] init];
    behavior.receiptPrintFlag = ReceiptPrintFlagNoReceipt;
    behavior.forceDuplicate = @"1";
    BOOL hasTip = (tipNum != nil && tipNum.intValue > 0);
    if (showTip && !hasTip) {
        behavior.tipRequestFlag = TipRequestFlagNeedEnterTipOnTerminal;
    } else {
        behavior.tipRequestFlag = TipRequestFlagNotNeedEnterTipOnTerminal;
    }
    behavior.continuousScreen = ContinuousScreenNotSet;
    req.transactionBehavior = behavior;

    return req;
}

- (void)applyRawCodes:(NSMutableDictionary *)map
               result:(PLExecutionResult *)result
         responseCode:(NSString *)responseCode
      responseMessage:(NSString *)responseMessage
                 host:(PLHostInformationResponse *)host
{
    [map setObject:(result.isSuccessful ? @"OK" : @"ERROR") forKey:@"execCode"];
    [map setObject:result.responseMessage ?: @"" forKey:@"execMessage"];
    [map setObject:responseCode ?: @"" forKey:@"responseCode"];
    [map setObject:responseMessage ?: @"" forKey:@"responseMessage"];
    [map setObject:host.hostResponseCode ?: @"" forKey:@"hostResponseCode"];
    [map setObject:host.hostResponseMessage ?: @"" forKey:@"hostResponseMessage"];
    [map setObject:host.issuerResponseCode ?: @"" forKey:@"issuerResponseCode"];
}

- (NSDictionary *)buildTransactionResponse:(PLDoCreditResponse *)rsp
                                    result:(PLExecutionResult *)result
                                      data:(NSDictionary *)data
{
    NSString *reqId = data[@"transactionId"] ?: data[@"id"] ?: @"";
    NSString *reqEcr = data[@"ecrRefNum"] ?: @"";
    NSMutableDictionary *map = [NSMutableDictionary new];
    if (result.isSuccessful) {
        NSNumber *amountNum = data[@"amount"];
        [map setObject:@YES forKey:@"status"];
        [map setObject:@YES forKey:@"isPaymentSuccess"];
        [map setObject:rsp.responseMessage ?: @"" forKey:@"message"];
        [map setObject:[self buildDoCreditResponseMap:rsp] forKey:@"data"];
        [map setObject:rsp.accountInformation.cardHolder ?: @"" forKey:@"cardHolder"];
        [map setObject:rsp.accountInformation.account ?: @"" forKey:@"cardNumber"];
        [map setObject:rsp.paymentEmvTag.appLabel ?: @"" forKey:@"cardType"];
        [map setObject:rsp.traceInformation.referenceNumber ?: @"" forKey:@"refNum"];
        [map setObject:rsp.traceInformation.ecrReferenceNumber ?: @"" forKey:@"ecrRefNum"];
        [map setObject:rsp.traceInformation.globalUid ?: @"" forKey:@"transactionId"];
        [map setObject:rsp.traceInformation.timeStamp ?: @"" forKey:@"transactionDateTime"];
        [map setObject:[self entryMethodFromRsp:rsp] forKey:@"entryMethod"];
        [map setObject:amountNum ? [NSString stringWithFormat:@"%d", amountNum.intValue] : @"0"
                forKey:@"amount"];
        [map setObject:rsp.amountInformation.tipAmount ?: @"" forKey:@"tipAmount"];
        [map setObject:rsp.amountInformation.merchantFee ?: @"" forKey:@"surcharge"];
        [map setObject:reqId forKey:@"id"];
        if (_lastSnInfo) [map setObject:_lastSnInfo forKey:@"sn"];
    } else {
        [map setObject:@NO forKey:@"status"];
        [map setObject:@NO forKey:@"isPaymentSuccess"];
        [map setObject:rsp.responseMessage ?: rsp.hostInformation.hostResponseMessage ?: result.responseMessage ?: @"Transaction failed"
                forKey:@"message"];
        [map setObject:[NSNull null] forKey:@"data"];
        [map setObject:reqEcr forKey:@"ecrRefNum"];
        [map setObject:reqId forKey:@"id"];
        if (_lastSnInfo) [map setObject:_lastSnInfo forKey:@"sn"];
    }
    [self applyRawCodes:map
                 result:result
           responseCode:rsp.responseCode
        responseMessage:rsp.responseMessage
                   host:rsp.hostInformation];
    return map;
}

- (NSDictionary *)buildDoCreditResponseMap:(PLDoCreditResponse *)rsp
{
    if (!rsp) return @{};
    NSMutableDictionary *map = [NSMutableDictionary new];

    [map setObject:rsp.responseCode ?: @"" forKey:@"responseCode"];
    [map setObject:rsp.responseMessage ?: @"" forKey:@"responseMessage"];
    [map setObject:[self entryMethodFromRsp:rsp] forKey:@"entryMethod"];
    [map setObject:rsp.traceInformation.globalUid ?: @"" forKey:@"transactionId"];

    PLAccountResponse *acc = rsp.accountInformation;
    [map setObject:@{
        @"account": acc.account ?: @"",
        @"cardHolder": acc.cardHolder ?: @"",
        @"cardExpireDate": acc.expireDate ?: @""
    } forKey:@"accountInformation"];

    PLTraceResponse *trace = rsp.traceInformation;
    [map setObject:@{
        @"referenceNumber": trace.referenceNumber ?: @"",
        @"ecrReferenceNumber": trace.ecrReferenceNumber ?: @"",
        @"timeStamp": trace.timeStamp ?: @"",
        @"authorizationCode": rsp.hostInformation.authorizationCode ?: @""
    } forKey:@"traceInformation"];

    PLAmountResponse *amt = rsp.amountInformation;
    [map setObject:@{
        @"transactionAmount": amt.approvedAmount ?: @"",
        @"tipAmount": amt.tipAmount ?: @"",
        @"merchantFee": amt.merchantFee ?: @""
    } forKey:@"amountInformation"];

    PLPaymentEmvTag *emv = rsp.paymentEmvTag;
    [map setObject:@{
        @"emvLabel": emv.appLabel ?: @"",
        @"emvPreferName": emv.appPreferName ?: @""
    } forKey:@"emv"];

    return map;
}

- (NSDictionary *)buildBatchCloseMap:(PLBatchCloseResponse *)rsp
{
    if (!rsp) return @{};
    NSMutableDictionary *map = [NSMutableDictionary new];

    [map setObject:rsp.responseCode ?: @"" forKey:@"responseCode"];
    [map setObject:rsp.responseMessage ?: @"" forKey:@"responseMessage"];
    [map setObject:rsp.tid ?: @"" forKey:@"tid"];
    [map setObject:rsp.mid ?: @"" forKey:@"mid"];
    [map setObject:rsp.timeStamp ?: @"" forKey:@"timeStamp"];
    [map setObject:rsp.failedCount ?: @"" forKey:@"failedCount"];
    [map setObject:rsp.failedTransactionNumber ?: @"" forKey:@"failedTransactionNumber"];
    [map setObject:rsp.safFailedCount ?: @"" forKey:@"safFailedCount"];
    [map setObject:rsp.safFailedTotal ?: @"" forKey:@"safFailedTotal"];

    if (rsp.hostInformation) {
        PLHostInformationResponse *h = rsp.hostInformation;
        [map setObject:@{
            @"hostResponseCode": h.hostResponseCode ?: @"",
            @"hostResponseMessage": h.hostResponseMessage ?: @"",
            @"authorizationCode": h.authorizationCode ?: @"",
            @"hostReferenceNumber": h.hostReferenceNumber ?: @"",
            @"batchNumber": h.batchNumber ?: @"",
            @"gatewayTransactionId": h.gatewayTransactionId ?: @"",
            @"hostDetailedMessage": h.hostDetailedMessage ?: @"",
            @"transactionIntegrityClass": h.transactionIntegrityClass ?: @"",
            @"retrievalReferenceNumber": h.retrievalReferenceNumber ?: @"",
            @"issuerResponseCode": h.issuerResponseCode ?: @"",
            @"paymentAccountReferenceId": h.paymentAccountReferenceId ?: @""
        } forKey:@"hostInformation"];
    }

    if (rsp.totalCount) {
        PLTotalCount *c = rsp.totalCount;
        [map setObject:@{
            @"creditCount": c.creditCount ?: @"",
            @"debitCount": c.debitCount ?: @"",
            @"ebtCount": c.ebtCount ?: @"",
            @"giftCount": c.giftCount ?: @"",
            @"loyaltyCount": c.loyaltyCount ?: @"",
            @"cashCount": c.cashCount ?: @""
        } forKey:@"totalCount"];
    }

    if (rsp.totalAmount) {
        PLTotalAmount *a = rsp.totalAmount;
        [map setObject:@{
            @"creditAmount": a.creditAmount ?: @"",
            @"debitAmount": a.debitAmount ?: @"",
            @"ebtAmount": a.ebtAmount ?: @"",
            @"giftAmount": a.giftAmount ?: @"",
            @"loyaltyAmount": a.loyaltyAmount ?: @"",
            @"cashAmount": a.cashAmount ?: @""
        } forKey:@"totalAmount"];
    }

    if (rsp.torInformation) {
        PLTorResponse *tor = rsp.torInformation;
        [map setObject:@[@{
            @"batchNumber": tor.batchNumber ?: @"",
            @"gatewayTransactionId": tor.gatewayTransactionId ?: @"",
            @"hostReferenceNumber": tor.hostReferenceNumber ?: @"",
            @"hostResponseCode": tor.hostResponseCode ?: @"",
            @"hostResponseMessage": tor.hostResponseMessage ?: @"",
            @"maskedPan": tor.maskedPan ?: @"",
            @"originalAmount": tor.originalAmount ?: @"",
            @"originalTransactionAuthorizationCode": tor.originalTransactionAuthorizationCode ?: @"",
            @"originalTransactionDateTime": tor.originalTransactionDateTime ?: @"",
            @"reversalAuthorizationCode": tor.reversalAuthorizationCode ?: @"",
            @"reversalTimeStamp": tor.reversalTimeStamp ?: @""
        }] forKey:@"torInformation"];
    }

    return map;
}

- (NSDictionary *)buildHistoryReportMap:(PLHistoryReportResponse *)rsp
{
    if (!rsp) return @{};
    NSMutableDictionary *map = [NSMutableDictionary new];

    [map setObject:rsp.batchNumber ?: @"" forKey:@"batchNumber"];
    [map setObject:rsp.timeStamp ?: @"" forKey:@"timeStamp"];

    if (rsp.edcTotalCount) {
        PLEdcTotalCount *c = rsp.edcTotalCount;
        [map setObject:@{
            @"creditCount": c.creditCount ?: @"",
            @"debitCount": c.debitCount ?: @"",
            @"ebtCount": c.ebtCount ?: @"",
            @"giftCount": c.giftCount ?: @"",
            @"loyaltyCount": c.loyaltyCount ?: @"",
            @"cashCount": c.cashCount ?: @""
        } forKey:@"totalCount"];
    }

    if (rsp.edcTotalAmount) {
        PLEdcTotalAmount *a = rsp.edcTotalAmount;
        [map setObject:@{
            @"creditAmount": a.creditAmount ?: @"",
            @"debitAmount": a.debitAmount ?: @"",
            @"ebtAmount": a.ebtAmount ?: @"",
            @"giftAmount": a.giftAmount ?: @"",
            @"loyaltyAmount": a.loyaltyAmount ?: @"",
            @"cashAmount": a.cashAmount ?: @""
        } forKey:@"totalAmount"];
    }

    return map;
}

- (NSString *)entryMethodFromRsp:(PLDoCreditResponse *)rsp
{
    PLAccountResponse *acc = rsp.accountInformation;
    PLPaymentEmvTag *emv = rsp.paymentEmvTag;
    if (!acc) return @"";
    switch (acc.entryMode) {
        case EntryModeManual:
            return (acc.cardPresentIndicator == CardPresentIndicatorCardNotPresent)
                ? @"KEYED_CNP" : @"KEYED_CP";
        case EntryModeSwipe:
            return @"SWIPED_MSD";
        case EntryModeContactless:
            return (emv && emv.tc.length > 0) ? @"CONTACTLESS_CHIP" : @"CONTACTLESS_MSD";
        case EntryModeLaserScanner:
            return @"SCANNER";
        case EntryModeChip:
            return @"CONTACT_CHIP";
        case EntryModeChipFallBackSwipe:
            return @"FALLBACK_SWIPED";
        default:
            return @"";
    }
}

#ifdef RCT_NEW_ARCH_ENABLED
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativePaxPoslinkSpecJSI>(params);
}
#endif

@end
