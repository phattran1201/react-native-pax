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
/**
 Camera Scan Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLCameraScanRequest.h"

@interface PLCameraScanRequest : PLRequest
/**
 Reader. Default is Rear camera. 
 */
@property (readwrite, nonatomic, assign)enum ReaderType reader;
/**
 Scan Timeout in 100ms. Valid value should be [100, 9999] minimum 10 seconds.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;


@end