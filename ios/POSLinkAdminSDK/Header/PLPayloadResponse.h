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
 Payload Response.
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLPayloadResponse.h"

@interface PLPayloadResponse : PLResponse
/**
 The response packet returned by the terminal. This is returned by the terminal in base64 format.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *payload;


@end