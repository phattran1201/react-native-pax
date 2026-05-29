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
 Error code 100010
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLCode100010.h"

@interface PLCode100010 : NSObject
/**
 Communication error 
 */
@property (readwrite, nonatomic, copy)NSString *commError;
/**
 Terminal is offline, online PIN is not available. 
 */
@property (readwrite, nonatomic, copy)NSString *terminalOfflinePinNotAvailable;

@end