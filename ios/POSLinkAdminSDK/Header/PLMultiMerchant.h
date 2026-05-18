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
 Multi Merchant Information. It is only used for POSLink Semi-Integration.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLMultiMerchant.h"

@interface PLMultiMerchant : NSObject
/**
 Used to indicate the specific merchant id, valid between [0, 24].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *multiMerchantId;
/**
 Used indicate the specific merchant name.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *multiMerchantName;

@end