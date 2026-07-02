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
 eWIC information request.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLEwicData.h>)
   #import <POSLinkAdmin/PLEwicData.h>
#elif __has_include("PLEwicData.h")
   #import "PLEwicData.h"
#endif


#if __has_include(<POSLinkAdmin/PLEwicInformationRequest.h>)
   #import <POSLinkAdmin/PLEwicInformationRequest.h>
#elif __has_include("PLEwicInformationRequest.h")
   #import "PLEwicInformationRequest.h"
#endif



@interface PLEwicInformationRequest : NSObject
/**
 The request eWIC product details. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLEwicData *> *ewicData;
/**
 The Discount for eWIC transactions.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *ewicDiscountAmount;

@end