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
 Set Apple Pay VAS Parameters Request
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLApplePayVas.h>)
   #import <POSLinkAdmin/PLApplePayVas.h>
#elif __has_include("PLApplePayVas.h")
   #import "PLApplePayVas.h"
#endif


#if __has_include(<POSLinkAdmin/PLSetApplePayVasParametersRequest.h>)
   #import <POSLinkAdmin/PLSetApplePayVasParametersRequest.h>
#elif __has_include("PLSetApplePayVasParametersRequest.h")
   #import "PLSetApplePayVasParametersRequest.h"
#endif



@interface PLSetApplePayVasParametersRequest : PLRequest
/**
 VAS mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum VasMode vasMode;
/**
 Apple Pay VAS specific data. 
 */
@property (readwrite, nonatomic, strong)PLApplePayVas *applePayVasData;


@end