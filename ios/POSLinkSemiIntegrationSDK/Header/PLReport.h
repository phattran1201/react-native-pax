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

#import <Foundation/Foundation.h>
#import "PLExecutionResult.h"
#import "PLBaseTerminal.h"
#import "PLHostReportRequest.h"
#import "PLHistoryReportRequest.h"
#import "PLSafSummaryReportRequest.h"
#import "PLLocalFailedReportRequest.h"
#import "PLLocalDetailReportRequest.h"
#import "PLHostDetailReportRequest.h"
#import "PLLocalTotalReportRequest.h"
#import "PLLocalDetailReportResponse.h"
#import "PLSafSummaryReportResponse.h"
#import "PLHistoryReportResponse.h"
#import "PLLocalTotalReportResponse.h"
#import "PLLocalFailedReportResponse.h"
#import "PLHostDetailReportResponse.h"
#import "PLHostReportResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLReport : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Host Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)hostReportWithRequest:(PLHostReportRequest *)request completion:(void(^)(PLHostReportResponse *response,PLExecutionResult *result))completion;

/**
 * History Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)historyReportWithRequest:(PLHistoryReportRequest *)request completion:(void(^)(PLHistoryReportResponse *response,PLExecutionResult *result))completion;

/**
 * SAF Summary Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)safSummaryReportWithRequest:(PLSafSummaryReportRequest *)request completion:(void(^)(PLSafSummaryReportResponse *response,PLExecutionResult *result))completion;

/**
 * Local Failed Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)localFailedReportWithRequest:(PLLocalFailedReportRequest *)request completion:(void(^)(PLLocalFailedReportResponse *response,PLExecutionResult *result))completion;

/**
 * Local Detail Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)localDetailReportWithRequest:(PLLocalDetailReportRequest *)request completion:(void(^)(PLLocalDetailReportResponse *response,PLExecutionResult *result))completion;

/**
 * Host Detail Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)hostDetailReportWithRequest:(PLHostDetailReportRequest *)request completion:(void(^)(PLHostDetailReportResponse *response,PLExecutionResult *result))completion;

/**
 * Local Total Report Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)localTotalReportWithRequest:(PLLocalTotalReportRequest *)request completion:(void(^)(PLLocalTotalReportResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

