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
 MAC Calculation Response.
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLMacCalculationResponse.h"

@interface PLMacCalculationResponse : PLResponse
/**
 The MAC result, represented in hexadecimal.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *resultData;
/**
 KSN value.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *ksn;


@end