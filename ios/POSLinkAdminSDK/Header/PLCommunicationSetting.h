/*
 * ============================================================================
 * = COPYRIGHT
 *          PAX Computer Technology(Shenzhen) Co., Ltd. PROPRIETARY INFORMATION
 *   This software is supplied under the terms of a license agreement or nondisclosure
 *   agreement with PAX Computer Technology(Shenzhen) Co., Ltd. and may not be copied or
 *   disclosed except in accordance with the terms in that agreement.
 *     Copyright (C) 2023 PAX Computer Technology(Shenzhen) Co., Ltd. All rights reserved.
 * ============================================================================
 */

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger,CommunicationType) {
    CommunicationTypeTCP = 1,
    CommunicationTypeSSL,
    CommunicationTypeHTTP,
    CommunicationTypeHTTPS,
    CommunicationTypeBLUETOOTH,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLCommunicationSetting : NSObject

/**
 * Communication type.
 */
@property (nonatomic, assign)CommunicationType communicationType;
/**
 * Transaction time out.
 * <p>-1: no timeout, but -1 only valid for "TCP", 60000 -default<br>
 * >0 wait n millisecond to timeout.<br>
 * measured in 1ms
 */
@property (nonatomic, strong)NSString *timeout;
/**
 * POS Terminal IP address
 * <p>For example "192.168.1.1"<br>
 * valid only while CommType is ETHERNET<br>
 */
@property (nonatomic, strong)NSString *destIP;
/**
 * Terminal port number
 * <p>value is "1" ~"65535"<br>
 * valid only while CommType is ETHERNET<br>
 */
@property (nonatomic, strong)NSString *destPort;
/**
 * Terminal bluetooth mac address
 * It is recommended to use the search function provided by the SDK to search out the Bluetooth address
 *
 * <p>For example is "E48242BF-FB84-D6F4-228D-1803CC7C48D8" "<br>
 * valid only while CommType is "BLUETOOTH"<br>
 */
@property (nonatomic, strong)NSString *bluetoothAddr;

@property (nonatomic, strong)NSString *enableJson;

+ (BOOL)isValidIP:(NSString *)ipAddress;

+ (BOOL)isNumberString:(NSString *)timeString;

+ (BOOL)validateNumber:(NSString*)number;

@end

NS_ASSUME_NONNULL_END
