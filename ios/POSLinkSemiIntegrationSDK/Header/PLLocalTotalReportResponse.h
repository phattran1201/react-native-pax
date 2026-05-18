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
#import "PLResponse.h"
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
#import "PLLocalTotalReportResponse.h"

@interface PLLocalTotalReportResponse : PLResponse
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Totals. 
 */
@property (readwrite, nonatomic, strong)PLTotals *totals;


@end