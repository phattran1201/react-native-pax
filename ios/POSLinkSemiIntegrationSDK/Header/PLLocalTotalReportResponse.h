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
 Local Total Report Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif


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


#if __has_include(<POSLinkAdmin/PLLocalTotalReportResponse.h>)
   #import <POSLinkAdmin/PLLocalTotalReportResponse.h>
#elif __has_include("PLLocalTotalReportResponse.h")
   #import "PLLocalTotalReportResponse.h"
#endif



@interface PLLocalTotalReportResponse : PLResponse
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Totals. 
 */
@property (readwrite, nonatomic, strong)PLTotals *totals;
/**
 The transaction type, total transaction amount, and count of transactions grouped by each transaction type.

 Attribute : ans...1024 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTotals;


@end