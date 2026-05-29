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
 Response Base Class.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLResponse.h"

@interface PLResponse : NSObject
/**
 Response code return from terminal. You can get the detail information from ResponseCode class.

 Attribute:ans6 
 */
@property (readwrite, nonatomic, copy)NSString *responseCode;
/**
 Response message return from terminal. If local error message exists, this field is mandatory.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *responseMessage;

@end