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
 Input Text Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLInputTextResponse.h"

@interface PLInputTextResponse : PLResponse
/**
 Text input by customer.

For currency input, 10000 will be returned if the customer input $100.00 on device.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *text;


@end