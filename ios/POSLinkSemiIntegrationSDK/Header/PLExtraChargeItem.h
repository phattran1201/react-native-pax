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


#if __has_include(<POSLinkAdmin/PLExtraChargeItem.h>)
   #import <POSLinkAdmin/PLExtraChargeItem.h>
#elif __has_include("PLExtraChargeItem.h")
   #import "PLExtraChargeItem.h"
#endif



@interface PLExtraChargeItem : NSObject
/**
 Item Type.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ExtraChargeItemType itemType;
/**
 The amount for the additional fee.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *extraChargeAmount;

@end