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
 Ewic Information Response.
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


#if __has_include(<POSLinkAdmin/PLEwicDetail.h>)
   #import <POSLinkAdmin/PLEwicDetail.h>
#elif __has_include("PLEwicDetail.h")
   #import "PLEwicDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLEwicBalance.h>)
   #import <POSLinkAdmin/PLEwicBalance.h>
#elif __has_include("PLEwicBalance.h")
   #import "PLEwicBalance.h"
#endif


#if __has_include(<POSLinkAdmin/PLEwicInformationResponse.h>)
   #import <POSLinkAdmin/PLEwicInformationResponse.h>
#elif __has_include("PLEwicInformationResponse.h")
   #import "PLEwicInformationResponse.h"
#endif



@interface PLEwicInformationResponse : NSObject
/**
 eWIC Balance information group.

 Attribute : ans...256 
 */
@property (readwrite, nonatomic, copy)NSArray<PLEwicBalance *> *ewicBalance;
/**
 eWIC Detail information group.

 Attribute : ans...256 
 */
@property (readwrite, nonatomic, copy)NSArray<PLEwicDetail *> *ewicDetail;
/**
 The earliest expiration date for the benefit among the items returned in ewicBalance. Format is YYYYMMDD.

 Attribute : n8 
 */
@property (readwrite, nonatomic, copy)NSString *earliestBenefitExpiryDate;

@end