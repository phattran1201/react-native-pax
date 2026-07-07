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
 VAS Push Data class
 */

#import <Foundation/Foundation.h>

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



@interface PLGoogleSmartTapPushService : NSObject
/**
 Security.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum Security security;
/**
 Bitmaps for the various capabilities that the ECR supports.

 Attribute : n32 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTapCapBitmap *googleSmartTapCap;
/**
 A predefined number specific to the merchant.

 Attribute : n8 
 */
@property (readwrite, nonatomic, copy)NSString *collectId;
/**
 Service usage. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLServiceUsage *> *googleServiceUsage;
/**
 Service update. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLServiceUpdate *> *googleServiceUpdate;
/**
 New service. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLNewService *> *googleNewService;
/**
 EndTap

Default is NormalFlow.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum EndTap endTap;

@end