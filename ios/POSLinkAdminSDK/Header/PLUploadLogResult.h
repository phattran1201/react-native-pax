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

NS_ASSUME_NONNULL_BEGIN

@interface PLUploadLogResult : NSObject
/**
 * Returns true if both the terminal and POSLink upload logs successfully.
*/
@property (nonatomic, assign) BOOL isSuccessful;
/**
  POSLink Upload Error Code:\n
  0 - OK\n
  1 - POSLink SFTP connect error\n
  2 - POSLink upload data error\n
  3 - POSLink no data to upload\n
*/
@property (nonatomic, strong) NSString *POSLinkUploadErrorCode;
/**
 * Terminal Upload Error Code:\n
  0 - OK\n
  1 - COMM ERROR\n
  2 - ABORTED\n
  3 - CONNECT ERROR\n
  4 - UNKNOW ERROR\n
  5 - SFTP COMM ERROR\n
  6 - NO DATA TO UPLOAD\n
*/
@property (nonatomic, strong) NSString *TerminalUploadErrorCode;
/**
 * Terminal SN.
*/
@property (nonatomic, strong) NSString *sn;

@end

NS_ASSUME_NONNULL_END
