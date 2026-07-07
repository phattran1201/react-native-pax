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
 Response Amount Information.
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


#if __has_include(<POSLinkAdmin/PLAmountResponse.h>)
   #import <POSLinkAdmin/PLAmountResponse.h>
#elif __has_include("PLAmountResponse.h")
   #import "PLAmountResponse.h"
#endif



@interface PLAmountResponse : NSObject
/**
 Approved amount, returned by the host, the format is $$$$$$$CC except Loyalty, if the EDC type is Loyalty, this field is approved points.

If the transaction type is not "Balance", this field is mandatory.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *approvedAmount;
/**
 The amount due $$$$$$$CC. Used in partial-authorization condition.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *amountDue;
/**
 The tip amount requested, $$$$$$$CC. If tip amount exists, this field is mandatory.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *tipAmount;
/**
 The cash back amount requested, $$$$$$$CC. If cash back amount exists, this is mandatory.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashBackAmount;
/**
 The merchant surcharge fee for DEBIT/EBT or CREDIT surcharge fee requested, $$$$$$$CC. If the merchant fee/surcharge fee exists, this is mandatory.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFee;
/**
 The tax amount requested, $$$$$$$CC. If tax amount exists, this is mandatory.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *taxAmount;
/**
 The cardholder's balance, $$$$$$$CC.

If the EDC is Ebt, this is the cash benefits balance.

If the EDC is Gift or Loyalty or Credit, this is host returned balance.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *balance1;
/**
 The cardholder's balance, $$$$$$$CC.

If the EDC is Ebt, this is the cash benefits balance.

If the EDC is Gift or Loyalty or Credit, this is host returned balance.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *balance2;
/**
 Service Fee for Credit and Debit transactions, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *serviceFee;
/**
 Any amount of the original authorization remaining after this void/refund, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *transactionRemainingAmount;
/**
 The tip amount approved by the host, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *approvedTipAmount;
/**
 The cash back amount approved by the host, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *approvedCashBackAmount;
/**
 The surcharge fee/Merchant fee approved by the host, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *approvedMerchantFee;
/**
 The tax amount approved by the host, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *approvedTaxAmount;
/**
 The cardholder's balance, $$$$$$$CC.

If the EDC is EBT, this is the farmer balance if returned by the host.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *balance3;
/**
 The discount amount, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *discountAmount;
/**
 The original tip amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *originalTipAmount;

@end