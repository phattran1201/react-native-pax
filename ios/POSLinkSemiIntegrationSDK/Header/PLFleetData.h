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
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLFleetData.h"

@interface PLFleetData : NSObject
/**
 Product code.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *productCode;
/**
 Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *productAmount;
/**
 Includes 3 implied decimals.

Example: If the price is a decimal such as $5.37, the number entered should be 5370. It needs 3 digits after the decimal point. If the price is a integer like $6, the number entered should be 6000.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *unitPrice;
/**
 Includes 3 implied decimals.

For Example: If quantity is a decimal such as 4.17, the number entered should be 4170. It needs 3 digits after the decimal point. If quantity is a integer like 6, the number entered should be 6000.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *quantity;
/**
 Unit of measure.

 Attribute:ans1 
 */
@property (readwrite, nonatomic, copy)NSString *unitOfMeasure;

@end