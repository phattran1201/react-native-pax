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
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLNewService.h"
#import "PLServiceUpdate.h"
#import "PLServiceUsage.h"
#import "PLGoogleSmartTapCapBitmap.h"
#import "PLGoogleSmartTapPushService.h"
#import "PLVasPushDataRequest.h"

@interface PLVasPushDataRequest : PLRequest
/**
 VAS mode. 
 */
@property (readwrite, nonatomic, assign)enum VasMode vasMode;
/**
 Vas Push Data 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTapPushService *googleSmartTapPushService;


@end