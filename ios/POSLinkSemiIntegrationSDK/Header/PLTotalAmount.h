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
 Total Amount. All amounts do not contain the voided. All amounts is net deposit amount.
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


#if __has_include(<POSLinkAdmin/PLTotalAmount.h>)
   #import <POSLinkAdmin/PLTotalAmount.h>
#elif __has_include("PLTotalAmount.h")
   #import "PLTotalAmount.h"
#endif



@interface PLTotalAmount : NSObject
/**
 CreditAmount: doesn't contain void and authorization transaction amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *creditAmount;
/**
 DebitAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *debitAmount;
/**
 EbtAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *ebtAmount;
/**
 GiftAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *giftAmount;
/**
 LoyaltyAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyAmount;
/**
 CashAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashAmount;
/**
 QR Code Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *qrCodeAmount;

@end