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
 EdcTotalAmount
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLEdcTotalAmount.h"

@interface PLEdcTotalAmount : NSObject
/**
 CreditAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *creditAmount;
/**
 DebitAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *debitAmount;
/**
 EbtAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *ebtAmount;
/**
 GiftAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *giftAmount;
/**
 LoyaltyAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyAmount;
/**
 CashAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashAmount;
/**
 CheckAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *checkAmount;

@end