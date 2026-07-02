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
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLLodgingItem.h>)
   #import <POSLinkAdmin/PLLodgingItem.h>
#elif __has_include("PLLodgingItem.h")
   #import "PLLodgingItem.h"
#endif



@interface PLLodgingItem : NSObject
/**
 The item type for the additional charge.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum AdditionalChargeItemType itemType;
/**
 The item amount.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *itemAmount;
/**
 The item code.

 Attribute : ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *itemCode;

@end