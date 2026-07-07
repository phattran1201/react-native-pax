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
 Request commercial information.
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


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLLineItemDetail.h>)
   #import <POSLinkAdmin/PLLineItemDetail.h>
#elif __has_include("PLLineItemDetail.h")
   #import "PLLineItemDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLCommercialRequest.h>)
   #import <POSLinkAdmin/PLCommercialRequest.h>
#elif __has_include("PLCommercialRequest.h")
   #import "PLCommercialRequest.h"
#endif



@interface PLCommercialRequest : NSObject
/**
 The order number supplied by the merchant.

 Attribute : ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *poNumber;
/**
 The reference identifier (e.g., Customer Code, Purchase Order Number, Cardholder Reference Number etc.) supplied by the commercial cardholder.

 Attribute : ans...17 
 */
@property (readwrite, nonatomic, copy)NSString *customerCode;
/**
 The indicator of tax exempt.

 Attribute : n...1 
 */
@property (readwrite, nonatomic, assign)enum TaxExemptIndicator taxExempt;
/**
 The tax exempt id.

 Attribute : ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *taxExemptId;
/**
 The merchant tax id.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *merchantTaxId;
/**
 The destination zip code. The application supports 5 to 9 characters including numbers, letters and space.

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *destinationZipCode;
/**
 The description of the purchase. The value of the Transaction Advice Addendum field, displays descriptive information about a transaction on a customer's AMEX card statement.

 Attribute : ans...40 
 */
@property (readwrite, nonatomic, copy)NSString *productDescription;
/**
 The ship from zip code. Valid for Visa and MasterCard. The application supports 5 to 9 characters including numbers, letters and space.

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *shipFromZipCode;
/**
 Destination country code of the goods being shipped. Usually, it should be number. U.S. should utilize 840.

Exception for TransIT: it should be Alpha-3 code.U.S.should utilize "USA"

 Attribute : an...3 
 */
@property (readwrite, nonatomic, copy)NSString *destinationCountryCode;
/**
 Used to report the amounts for different Tax Types in the transaction. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLTaxDetail *> *taxDetails;
/**
 An international description code of the overall goods or services being supplied. The acquirer bank or processor should provide the merchant an updated listing of currently defined codes. Valid for Visa.

 Attribute : ans...4 
 */
@property (readwrite, nonatomic, copy)NSString *summaryCommodityCode;
/**
 Amount of any discount applied by the merchant, valid for Visa.

 Attribute : n...12 
 */
@property (readwrite, nonatomic, copy)NSString *discountAmount;
/**
 Freight or shipping portion of the total transaction amount, valid for Visa and MasterCard.

 Attribute : n...12 
 */
@property (readwrite, nonatomic, copy)NSString *freightAmount;
/**
 Fee amount associated with the import of the purchased goods. , valid for Visa and MasterCard.

 Attribute : n...12 
 */
@property (readwrite, nonatomic, copy)NSString *dutyAmount;
/**
 Purchase order date and must be supplied in YYMMDD format, valid for Visa.

 Attribute : n6 
 */
@property (readwrite, nonatomic, copy)NSString *orderDate;
/**
 Line item details. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLLineItemDetail *> *lineItemDetails;
/**
 The shipping company name or ID.

 Attribute : ans...50 
 */
@property (readwrite, nonatomic, copy)NSString *shippingCompany;
/**
 The shipment's tracking number.

 Attribute : ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *shippingTrackingNumber;
/**
 Additional fees.

 Attribute : n...12 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFees;
/**
 Force terminal to do commercial transaction flag.

Default is No.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ForceCc forceCc;

@end