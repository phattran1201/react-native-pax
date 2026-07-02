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
 Request Amount Information.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAmountRequest.h>)
   #import <POSLinkAdmin/PLAmountRequest.h>
#elif __has_include("PLAmountRequest.h")
   #import "PLAmountRequest.h"
#endif



@interface PLAmountRequest : NSObject
/**
 The base amount, the format is $$$$$$$CC except LOYALTY, if the transaction is Loyalty, this field is the points. if this field is NULL, terminal will prompt dialog to enter the amount.

If the terminal is under demo mode, running transactions with special amount will trigger special results. Please refer to POSLink - Reference - Special Amount in Demo Mode for more details.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *transactionAmount;
/**
 The tip amount, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *tipAmount;
/**
 The cash back amount, $$$$$$$CC; If the field is NULL and cash back is enabled on the application, terminal will prompt dialog to enter the amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashBackAmount;
/**
 The merchant surcharge fee for DEBIT/EBT or CREDIT surcharge fee, $$$$$$$CC. If the setting on terminal of "merchant fee" is 0, this field must be NULL or 0.If the setting on terminal of "merchant fee" is not 0, this field can be present or NULL, if the value is NULL, terminal will use the default value in terminal. only Debit sale and EBT cash benefit sale support it.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFee;
/**
 The tax amount, $$$$$$$CC, if the field is NULL, and terminal supports commercial card, terminal will prompt dialog to enter it.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *taxAmount;
/**
 The portion of the transaction amount charged for fuel purchases during fleet transactions. This amount is pre-included in the transaction base amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fuelAmount;
/**
 Service Fee for Credit and Debit transactions, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *serviceFee;
/**
 The Original Amount, $$$$$$$CC.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *originalAmount;

@end