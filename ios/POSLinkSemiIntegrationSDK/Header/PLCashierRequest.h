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
 Request cashier information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCashierRequest.h"

@interface PLCashierRequest : NSObject
/**
 The clerk id or server id.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *clerkId;
/**
 The shift id number.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *shiftId;

@end