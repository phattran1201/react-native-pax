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
 Total Data
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCheckTotals.h"
#import "PLCashTotals.h"
#import "PLLoyaltyTotals.h"
#import "PLGiftTotals.h"
#import "PLEbtTotals.h"
#import "PLDebitTotals.h"
#import "PLCreditTotals.h"
#import "PLTotals.h"

@interface PLTotals : NSObject
/**
 Credit Totals 
 */
@property (readwrite, nonatomic, strong)PLCreditTotals *creditTotals;
/**
 Debit Totals 
 */
@property (readwrite, nonatomic, strong)PLDebitTotals *debitTotals;
/**
 EBT Totals 
 */
@property (readwrite, nonatomic, strong)PLEbtTotals *ebtTotals;
/**
 Gift Totals 
 */
@property (readwrite, nonatomic, strong)PLGiftTotals *giftTotals;
/**
 Loyalty Totals 
 */
@property (readwrite, nonatomic, strong)PLLoyaltyTotals *loyaltyTotals;
/**
 Cash Totals 
 */
@property (readwrite, nonatomic, strong)PLCashTotals *cashTotals;
/**
 Check Totals 
 */
@property (readwrite, nonatomic, strong)PLCheckTotals *checkTotals;

@end