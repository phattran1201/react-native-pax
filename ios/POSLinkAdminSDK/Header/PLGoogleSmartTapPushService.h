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

#import "PLAdminConst.h"
#import "PLNewService.h"
#import "PLServiceUpdate.h"
#import "PLServiceUsage.h"
#import "PLGoogleSmartTapCapBitmap.h"
#import "PLGoogleSmartTapPushService.h"

@interface PLGoogleSmartTapPushService : NSObject
/**
 Security. 
 */
@property (readwrite, nonatomic, assign)enum Security security;
/**
 Bitmaps for the various capabilities that the ECR supports. 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTapCapBitmap *googleSmartTapCap;
/**
 A predefined number specific to the merchant.

 Attribute:n8 
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
 */
@property (readwrite, nonatomic, assign)enum EndTap endTap;

@end