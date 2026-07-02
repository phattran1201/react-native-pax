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


#if __has_include(<POSLinkAdmin/PLCashTotals.h>)
   #import <POSLinkAdmin/PLCashTotals.h>
#elif __has_include("PLCashTotals.h")
   #import "PLCashTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLLoyaltyTotals.h>)
   #import <POSLinkAdmin/PLLoyaltyTotals.h>
#elif __has_include("PLLoyaltyTotals.h")
   #import "PLLoyaltyTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLGiftTotals.h>)
   #import <POSLinkAdmin/PLGiftTotals.h>
#elif __has_include("PLGiftTotals.h")
   #import "PLGiftTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLEbtTotals.h>)
   #import <POSLinkAdmin/PLEbtTotals.h>
#elif __has_include("PLEbtTotals.h")
   #import "PLEbtTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLDebitTotals.h>)
   #import <POSLinkAdmin/PLDebitTotals.h>
#elif __has_include("PLDebitTotals.h")
   #import "PLDebitTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLCreditTotals.h>)
   #import <POSLinkAdmin/PLCreditTotals.h>
#elif __has_include("PLCreditTotals.h")
   #import "PLCreditTotals.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotals.h>)
   #import <POSLinkAdmin/PLTotals.h>
#elif __has_include("PLTotals.h")
   #import "PLTotals.h"
#endif



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

@end