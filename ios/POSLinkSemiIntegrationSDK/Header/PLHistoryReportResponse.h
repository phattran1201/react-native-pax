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
 History Report Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLEdcTotalAmount.h"
#import "PLEdcTotalCount.h"
#import "PLHistoryReportResponse.h"

@interface PLHistoryReportResponse : PLResponse
/**
 EDCTotal count 
 */
@property (readwrite, nonatomic, strong)PLEdcTotalCount *edcTotalCount;
/**
 EDC Total amount 
 */
@property (readwrite, nonatomic, strong)PLEdcTotalAmount *edcTotalAmount;
/**
 The date time, YYYYMMDDhhmmss.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 The batch number of last batch.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;


@end