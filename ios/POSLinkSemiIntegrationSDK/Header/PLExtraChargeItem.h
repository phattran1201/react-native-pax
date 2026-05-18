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
 The class for extra charge item.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLExtraChargeItem.h"

@interface PLExtraChargeItem : NSObject
/**
 Item Type. 
 */
@property (readwrite, nonatomic, assign)enum ExtraChargeItemType itemType;
/**
 The amount for the additional fee.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *extraChargeAmount;

@end