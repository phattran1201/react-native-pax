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
 Fleet Data.
Please Note：This class can not be set it with FsaData or EwicData at the same time.
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


#if __has_include(<POSLinkAdmin/PLFleetData.h>)
   #import <POSLinkAdmin/PLFleetData.h>
#elif __has_include("PLFleetData.h")
   #import "PLFleetData.h"
#endif



@interface PLFleetData : NSObject
/**
 Product code identifying the specified product or service purchased. See SemiIntegrationReference - Conexxus Product Codes for details about recognized product codes.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *productCode;
/**
 Total price of the specified product or service purchased. Value is a fixed-point decimal amount with two digits of precision.

For example, the value '12345' shall be interpreted as an amount of 123.45

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *productAmount;
/**
 Price per unit of the specified product or service purchased. Value is a fixed-point decimal with three digits of precision.

For example, the value '6000' shall be interpreted as a unit price of $6.000.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *unitPrice;
/**
 Total quantity of the specified product or service purchased. Value is a fixed-point decimal with three digits of precision.

For example, the value '4170' shall be interpreted as a quantity of 4.170.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *quantity;
/**
 Unit of measure for the quantity of the specified product or service purchased. Acceptable values are host dependent.

 Attribute : ans1 
 */
@property (readwrite, nonatomic, copy)NSString *unitOfMeasure;

@end