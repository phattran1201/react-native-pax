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
 SAF Summary Report Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCardTotalAmount.h"
#import "PLCardTotalCount.h"
#import "PLSafSummaryReportResponse.h"

@interface PLSafSummaryReportResponse : PLResponse
/**
 Total count separated by card type. 
 */
@property (readwrite, nonatomic, strong)PLCardTotalCount *cardTotalCount;
/**
 Total Amount separated by card type. 
 */
@property (readwrite, nonatomic, strong)PLCardTotalAmount *cardTotalAmount;


@end