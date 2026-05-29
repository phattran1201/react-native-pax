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
 Lodging item.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLLodgingItem.h"

@interface PLLodgingItem : NSObject
/**
 The item type for the additional charge. 
 */
@property (readwrite, nonatomic, assign)enum AdditionalChargeItemType itemType;
/**
 The item amount.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *itemAmount;
/**
 The item code.

 Attribute:ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *itemCode;

@end