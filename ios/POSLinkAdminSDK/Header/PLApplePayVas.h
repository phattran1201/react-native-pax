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
 Apple Pay Vas
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLApplePayVas.h"

@interface PLApplePayVas : NSObject
/**
 Max 3 merchant ID connect by '#',Each merchant ID(0, 36].

 Attribute:ans...110 
 */
@property (readwrite, nonatomic, copy)NSString *merchantId;
/**
 Url Mode. 
 */
@property (readwrite, nonatomic, assign)enum UrlMode urlMode;
/**
 Merchant URL.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *url;

@end