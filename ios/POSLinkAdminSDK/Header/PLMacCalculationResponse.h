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
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLMacCalculationResponse.h>)
   #import <POSLinkAdmin/PLMacCalculationResponse.h>
#elif __has_include("PLMacCalculationResponse.h")
   #import "PLMacCalculationResponse.h"
#endif



@interface PLMacCalculationResponse : PLResponse
/**
 The MAC result, represented in hexadecimal.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *resultData;
/**
 KSN value.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *ksn;


@end