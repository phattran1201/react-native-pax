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
 Request AVS information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAvsRequest.h"

@interface PLAvsRequest : NSObject
/**
 The zip code, only CREDIT supports it. the min length is 5 bytes.

 Attribute:ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *zipCode;
/**
 The primary address of cardholder. the actual max length is dependence on host. It can't be more than 32 bytes.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address;
/**
 The address of cardholder. the actual max length is dependence on host. It can't be more than 32 bytes.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address2;

@end