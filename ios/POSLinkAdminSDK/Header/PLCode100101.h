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
 Error code 100101
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLCode100101.h"

@interface PLCode100101 : NSObject
/**
 The specific host credential required for the transaction is not set. Please check the TMS file build and add the missing parameter. 
 */
@property (readwrite, nonatomic, copy)NSString *hostVarNameNotSet;
/**
 Host received an error during online authorization. Transaction reversal sent. 
 */
@property (readwrite, nonatomic, copy)NSString *hostReceiveError;

@end