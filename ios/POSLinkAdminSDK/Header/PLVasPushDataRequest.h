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
 Vas Push Data Request
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


#if __has_include(<POSLinkAdmin/PLNewService.h>)
   #import <POSLinkAdmin/PLNewService.h>
#elif __has_include("PLNewService.h")
   #import "PLNewService.h"
#endif


#if __has_include(<POSLinkAdmin/PLServiceUpdate.h>)
   #import <POSLinkAdmin/PLServiceUpdate.h>
#elif __has_include("PLServiceUpdate.h")
   #import "PLServiceUpdate.h"
#endif


#if __has_include(<POSLinkAdmin/PLServiceUsage.h>)
   #import <POSLinkAdmin/PLServiceUsage.h>
#elif __has_include("PLServiceUsage.h")
   #import "PLServiceUsage.h"
#endif


#if __has_include(<POSLinkAdmin/PLGoogleSmartTapCapBitmap.h>)
   #import <POSLinkAdmin/PLGoogleSmartTapCapBitmap.h>
#elif __has_include("PLGoogleSmartTapCapBitmap.h")
   #import "PLGoogleSmartTapCapBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLGoogleSmartTapPushService.h>)
   #import <POSLinkAdmin/PLGoogleSmartTapPushService.h>
#elif __has_include("PLGoogleSmartTapPushService.h")
   #import "PLGoogleSmartTapPushService.h"
#endif


#if __has_include(<POSLinkAdmin/PLVasPushDataRequest.h>)
   #import <POSLinkAdmin/PLVasPushDataRequest.h>
#elif __has_include("PLVasPushDataRequest.h")
   #import "PLVasPushDataRequest.h"
#endif



@interface PLVasPushDataRequest : PLRequest
/**
 VAS mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum VasMode vasMode;
/**
 Vas Push Data 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTapPushService *googleSmartTapPushService;


@end