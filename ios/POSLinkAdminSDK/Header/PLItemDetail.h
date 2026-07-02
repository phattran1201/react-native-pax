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
 Item Detail.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLItemDetail.h>)
   #import <POSLinkAdmin/PLItemDetail.h>
#elif __has_include("PLItemDetail.h")
   #import "PLItemDetail.h"
#endif



@interface PLItemDetail : NSObject
/**
 Product name.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *productName;
/**
 PLU or UPC data for report only, won't be displayed on the screen.

 Attribute : n...16 
 */
@property (readwrite, nonatomic, copy)NSString *pluCode;
/**
 Product total price.

Format can be either [symbol]$$$$$$CC or $$$$$$CC[symbol] or[symbol]$$$$$$CC[symbol].

The following symbols are supported: "-", "(", ")".

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *price;
/**
 Unit.

Default is PerItem.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ItemDetailUnit unit;
/**
 Produce price per unit. Format is $$$$$$CC.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *unitPrice;
/**
 Product total tax for report only, won't be displayed on the screen. Format is $$$$$$CC.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *tax;
/**
 Product quantity (depends on the unit) for example, 10 = 10 item, 10 = 10 pound, 10 = 10 feet.

 Attribute : ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *quantity;
/**
 Product image name, the image is preloaded on the terminal. Optional and only for Px5 and Px7.

If there is more than one item in request, this field is invalid.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *productImageName;
/**
 Product name or description, Optional and only for Px5 and Px7.

If there is more than one item in request, this field is invalid.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *productImageDescription;

@end