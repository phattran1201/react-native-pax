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
 eWIC Detail information group.
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


#if __has_include(<POSLinkAdmin/PLEwicDetail.h>)
   #import <POSLinkAdmin/PLEwicDetail.h>
#elif __has_include("PLEwicDetail.h")
   #import "PLEwicDetail.h"
#endif



@interface PLEwicDetail : NSObject
/**
 This field identifies whether the group contains UPC or PLU data.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum EwicGroupType upcPluInd;
/**
 This field contains the UPC or PLU data.

 Attribute : n...16 
 */
@property (readwrite, nonatomic, copy)NSString *upcPluData;
/**
 This field represents the store price per unit. Default format is $$$$$$CC.

 Attribute : n6 
 */
@property (readwrite, nonatomic, copy)NSString *upcPrice;
/**
 This field represents the number of items or the total weight of items for a particular UPC/PLU. Include 2 implied decimals.

 Attribute : n...5 
 */
@property (readwrite, nonatomic, copy)NSString *upcQty;
/**
 Action code

 Attribute : n...5 
 */
@property (readwrite, nonatomic, copy)NSString *actionCode;
/**
 This field represents the store price per unit. Default format is $$$$$$CC.

 Attribute : n6 
 */
@property (readwrite, nonatomic, copy)NSString *originalPrice;
/**
 This field represents the number of items or the total weight of items for a particular UPC/PLU. Include 2 implied decimals.

 Attribute : n...5 
 */
@property (readwrite, nonatomic, copy)NSString *originalQty;

@end