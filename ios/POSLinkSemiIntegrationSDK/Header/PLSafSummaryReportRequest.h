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
 SAF Summary Report Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLSafSummaryReportRequest.h"

@interface PLSafSummaryReportRequest : PLRequest
/**
 Store and forward transaction report indicator. 
 */
@property (readwrite, nonatomic, assign)enum SafReportIndicator safIndicator;


@end