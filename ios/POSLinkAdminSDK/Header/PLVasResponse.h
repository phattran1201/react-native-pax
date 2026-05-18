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
 Response VAS Information.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLVasResponse.h"

@interface PLVasResponse : NSObject
/**
 VAS response code. 
 */
@property (readwrite, nonatomic, assign)enum VasResponseCode vasCode;
/**
 Tokens returned from card. 
 */
@property (readwrite, nonatomic, copy)NSArray<NSString *> *vasData;
/**
 Google Smart Tap response data in format of NEDF, the message will be encoded with Base64.

 Attribute:ans...1024 
 */
@property (readwrite, nonatomic, copy)NSString *ndefData;

@end