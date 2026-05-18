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
 Tax detail.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTaxDetail.h"

@interface PLTaxDetail : NSObject
/**
 The type of the tax. 
 */
@property (readwrite, nonatomic, assign)enum TaxType taxType;
/**
 Tax Amount. The portion of the amount that represents the tax of field 1. Includes 2 implied decimals.

 Attribute:n...12 
 */
@property (readwrite, nonatomic, copy)NSString *taxAmount;
/**
 The rate of tax of field 1. Includes 2 implied decimals.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *taxRate;
/**
 When Tax Type is 00(Unknown) or 01(Federal/National Sales Tax), this field is merchant's federal tax ID.

When Tax Type is 07(Value Added Tax (VAT)), this field is merchant's VAT registration number.

 Attribute:ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *merchantTaxId;
/**
 When Tax Type is 00(Unknown) or 01(Federal/National Sales Tax), this field is customer's federal tax ID.

When Tax Type is 07(Value Added Tax (VAT)), this field is customer's VAT registration number.

 Attribute:ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *customerTaxId;
/**
 Valid when Tax Type = 07(Value Added Tax (VAT))

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *valueAddedTaxInvoiceNumber;
/**
 The alternate tax identifier description for the line item.

 Attribute:n...12 
 */
@property (readwrite, nonatomic, copy)NSString *alternateTaxId;

@end