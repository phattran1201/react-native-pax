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
 Response Restaurant Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLRestaurant.h"

@interface PLRestaurant : NSObject
/**
 The table number.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *tableNumber;
/**
 The guest number.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumber;
/**
 The ticket number.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *ticketNumber;

@end