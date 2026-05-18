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
#import "PLTransactionBehavior.h"
#import "PLAccountResponse.h"
#import "PLBatchCloseRequest.h"
#import "PLBatchCloseResponse.h"
#import "PLHistoryReportRequest.h"
#import "PLHistoryReportResponse.h"
#import "PLLocalDetailReportRequest.h"
#import "PLLocalDetailReportResponse.h"
#import "PLPaymentTransactionInformation.h"
#import "PLPaymentEmvTag.h"
#import "PLHostResponse.h"
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

static PLSemiTerminal *_terminal = nil;
static NSDictionary *_lastSnInfo = nil;

@implementation PaxPoslink

RCT_EXPORT_MODULE(PaxPoslink)

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
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @try {
            PLCommunicationSetting *comm = [[PLCommunicationSetting alloc] init];
            comm.communicationType = CommunicationTypeTCP;
            comm.destIP = ip;
            comm.destPort = (port && port.length > 0) ? port : @"10009";
            comm.timeout = timeout ? [NSString stringWithFormat:@"%d", timeout.intValue] : @"60000";

            NSString *tcpInfo = [NSString stringWithFormat:@"ip=%@, port=%@, timeout=%@",
                                 ip, comm.destPort, comm.timeout];

            PLSemiTerminal *terminal = [[POSLinkSemi getInstance]
                                        getTerminalWithCommunicationSetting:comm];
            if (terminal == nil) {
                reject(@"INIT_ERROR",
                       [NSString stringWithFormat:@"Create terminal failed! %@", tcpInfo],
                       nil);
                return;
            }
            _terminal = terminal;

            PLInitRequest *initReq = [[PLInitRequest alloc] init];
            [[terminal getManage] initWithRequest:initReq
                                       completion:^(PLInitResponse *rsp, PLExecutionResult *result) {
                if (rsp == nil || rsp.sn.length == 0) {
                    reject(@"INIT_ERROR",
                           [NSString stringWithFormat:@"Create terminal failed! %@", tcpInfo],
                           nil);
                    return;
                }
                NSDictionary *snInfo = @{
                    @"serialNumber": rsp.sn ?: @"",
                    @"modelName": rsp.modelName ?: @"",
                    @"appName": rsp.appName ?: @""
                };
                _lastSnInfo = snInfo;
                NSMutableDictionary *map = [NSMutableDictionary new];
                [map setObject:@YES forKey:@"status"];
                [map setObject:[NSString stringWithFormat:@"Create terminal success! %@", tcpInfo]
                        forKey:@"message"];
                [map setObject:@YES forKey:@"isPaymentSuccess"];
                [map setObject:snInfo forKey:@"serialNumber"];
                resolve(map);
            }];
        } @catch (NSException *e) {
            reject(@"INIT_ERROR", e.reason ?: @"Unknown error", nil);
        }
    });
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
        PLHistoryReportRequest *req = [[PLHistoryReportRequest alloc] init];
        [[_terminal getReport] historyReportWithRequest:req
                                            completion:^(PLHistoryReportResponse *rsp, PLExecutionResult *result) {
            NSMutableDictionary *map = [NSMutableDictionary new];
            if (result.isSuccessful) {
                [map setObject:@YES forKey:@"status"];
                [map setObject:rsp.responseMessage ?: @"Success" forKey:@"message"];
                [map setObject:[self buildHistoryReportMap:rsp] forKey:@"data"];
            } else {
                [map setObject:@NO forKey:@"status"];
                [map setObject:result.responseMessage ?: @"Get batch information error" forKey:@"message"];
            }
            resolve(map);
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

#pragma mark - cancelInit

- (void)cancelInit:(RCTPromiseResolveBlock)resolve
            reject:(RCTPromiseRejectBlock)reject
{
    @try {
        if (_terminal != nil) {
            NSError *error;
            [_terminal cancelWithError:&error];
            [[POSLinkSemi getInstance] removeTerminal:_terminal];
            _terminal = nil;
        }
        resolve(@"Cancel Init Success");
    } @catch (NSException *e) {
        reject(@"CANCEL_ERROR", e.reason ?: @"Cancel init error", nil);
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

RCT_REMAP_METHOD(cancelInit,
                 cancelInitWithResolve:(RCTPromiseResolveBlock)resolve
                 reject:(RCTPromiseRejectBlock)reject)
{
    [self cancelInit:resolve reject:reject];
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

    PLTransactionBehavior *behavior = [[PLTransactionBehavior alloc] init];
    behavior.receiptPrintFlag = ReceiptPrintFlagNoReceipt;
    behavior.forceDuplicate = @"1";
    BOOL hasTip = (tipNum != nil && tipNum.intValue > 0);
    if (showTip && !hasTip) {
        behavior.tipRequestFlag = TipRequestFlagNeedEnterTipOnTerminal;
    } else {
        behavior.tipRequestFlag = TipRequestFlagNotNeedEnterTipOnTerminal;
    }
    req.transactionBehavior = behavior;
    req.continuousScreen = ContinuousScreenNotSet;

    return req;
}

- (NSDictionary *)buildTransactionResponse:(PLDoCreditResponse *)rsp
                                    result:(PLExecutionResult *)result
                                      data:(NSDictionary *)data
{
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
        [map setObject:rsp.paymentTransactionInformation.globalUid ?: @"" forKey:@"transactionId"];
        [map setObject:rsp.traceInformation.timeStamp ?: @"" forKey:@"transactionDateTime"];
        [map setObject:[self entryMethodFromRsp:rsp] forKey:@"entryMethod"];
        [map setObject:amountNum ? [NSString stringWithFormat:@"%d", amountNum.intValue] : @"0"
                forKey:@"amount"];
        [map setObject:rsp.amountInformation.tipAmount ?: @"" forKey:@"tipAmount"];
        [map setObject:rsp.amountInformation.merchantFee ?: @"" forKey:@"surcharge"];
        if (_lastSnInfo) [map setObject:_lastSnInfo forKey:@"sn"];
    } else {
        [map setObject:@NO forKey:@"status"];
        [map setObject:@NO forKey:@"isPaymentSuccess"];
        [map setObject:rsp.responseMessage ?: result.responseMessage ?: @"Transaction failed"
                forKey:@"message"];
        [map setObject:[NSNull null] forKey:@"data"];
    }
    return map;
}

- (NSDictionary *)buildDoCreditResponseMap:(PLDoCreditResponse *)rsp
{
    if (!rsp) return @{};
    NSMutableDictionary *map = [NSMutableDictionary new];

    [map setObject:rsp.responseCode ?: @"" forKey:@"responseCode"];
    [map setObject:rsp.responseMessage ?: @"" forKey:@"responseMessage"];
    [map setObject:[self entryMethodFromRsp:rsp] forKey:@"entryMethod"];
    [map setObject:rsp.paymentTransactionInformation.globalUid ?: @"" forKey:@"transactionId"];

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
        @"authorizationCode": trace.authorizationResponse ?: @""
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
        PLHostResponse *h = rsp.hostInformation;
        [map setObject:@{
            @"hostResponseCode": h.hostResponseCode ?: @"",
            @"hostResponseMessage": h.hostResponseMessage ?: @"",
            @"authorizationCode": h.authorizationCode ?: @"",
            @"hostReferenceNumber": h.hostReferenceNumber ?: @"",
            @"traceNumber": h.traceNumber ?: @"",
            @"batchNumber": h.batchNumber ?: @"",
            @"transactionIdentifier": h.transactionIdentifier ?: @"",
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
            @"cashCount": c.cashCount ?: @"",
            @"checkCount": c.checkCount ?: @""
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
            @"cashAmount": a.cashAmount ?: @"",
            @"checkAmount": a.checkAmount ?: @""
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
            @"cashCount": c.cashCount ?: @"",
            @"checkCount": c.checkCount ?: @""
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
            @"cashAmount": a.cashAmount ?: @"",
            @"checkAmount": a.checkAmount ?: @""
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
