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
 Local Failed Report Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTraceResponse.h"
#import "PLAccountResponse.h"
#import "PLAmountResponse.h"
#import "PLHostResponse.h"
#import "PLLocalFailedReportResponse.h"

@interface PLLocalFailedReportResponse : PLResponse
/**
 Host information 
 */
@property (readwrite, nonatomic, strong)PLHostResponse *hostInformation;
/**
 EDC type 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Transaction Type 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Amount information 
 */
@property (readwrite, nonatomic, strong)PLAmountResponse *amountInformation;
/**
 Account information 
 */
@property (readwrite, nonatomic, strong)PLAccountResponse *accountInformation;
/**
 Trace information 
 */
@property (readwrite, nonatomic, strong)PLTraceResponse *traceInformation;


@end