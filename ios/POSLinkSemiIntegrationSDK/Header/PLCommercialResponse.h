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
 Response Commercial Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCommercialResponse.h"

@interface PLCommercialResponse : NSObject
/**
 The order number supplied by the merchant.

 Attribute:ans...17 
 */
@property (readwrite, nonatomic, copy)NSString *poNumber;
/**
 The reference identifier (e.g., Customer Code, Purchase Order Number, Cardholder Reference Number etc.) supplied by the commercial cardholder.

 Attribute:ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *customerCode;
/**
 The indicator of tax exempt. 
 */
@property (readwrite, nonatomic, assign)enum TaxExemptIndicator taxExempt;
/**
 The tax exempt id, if the value of tax exempt is "1", this field is mandatory.

 Attribute:ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *taxExemptId;
/**
 The merchant tax id, will be returned if terminal supports commercial card and this value manual entered.

 Attribute:ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *merchantTaxId;
/**
 The destination zip code which will be returned if terminal supports commercial card and this value manual entered.

 Attribute:ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *destinationZipCode;
/**
 The product description, will be returned if terminal supports commercial card and this value manual entered.

 Attribute:ans...40 
 */
@property (readwrite, nonatomic, copy)NSString *productDescription;

@end