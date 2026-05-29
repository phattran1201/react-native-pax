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
 Line item detail.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTaxDetail.h"
#import "PLLineItemDetail.h"

@interface PLLineItemDetail : NSObject
/**
 Line item sequence number.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *itemSequenceNumber;
/**
 Line item product code.

 Attribute:ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *productCode;
/**
 Line item commodity code. The international description code used to classify the item purchased.

 Attribute:ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *itemCommodityCode;
/**
 Specific description of the item purchased and related to the commodity code.

 Attribute:ans...35 
 */
@property (readwrite, nonatomic, copy)NSString *itemDescription;
/**
 This field represents the number of units of the item purchased.

 Attribute:n..12 
 */
@property (readwrite, nonatomic, copy)NSString *itemQuantity;
/**
 The unit of measure code, refer to unit of measure sheet.

 Attribute:ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *itemMeasurementUnit;
/**
 The unit price of the item purchased.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *itemUnitPrice;
/**
 Discount amount applied to the item purchased.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *itemDiscountAmount;
/**
 The rate at which the item is discounted.Includes 2 implied decimals.

 Attribute:n...5 
 */
@property (readwrite, nonatomic, copy)NSString *itemDiscountRate;
/**
 Tax Details. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLTaxDetail *> *taxDetails;
/**
 Unit cost multiplied by the quantity and less the discount per line item.

 Attribute:n...12 
 */
@property (readwrite, nonatomic, copy)NSString *lineItemTotal;

@end