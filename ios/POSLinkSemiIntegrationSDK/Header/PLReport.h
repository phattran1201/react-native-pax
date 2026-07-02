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
#if __has_include(<POSLinkAdmin/PLExecutionResult.h>)
   #import <POSLinkAdmin/PLExecutionResult.h>
#elif __has_include("PLExecutionResult.h")
   #import "PLExecutionResult.h"
#endif



#if __has_include(<POSLinkAdmin/PLBaseTerminal.h>)
   #import <POSLinkAdmin/PLBaseTerminal.h>
#elif __has_include("PLBaseTerminal.h")
   #import "PLBaseTerminal.h"
#endif



#if __has_include(<POSLinkAdmin/PLHostReportRequest.h>)
   #import <POSLinkAdmin/PLHostReportRequest.h>
#elif __has_include("PLHostReportRequest.h")
   #import "PLHostReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLHistoryReportRequest.h>)
   #import <POSLinkAdmin/PLHistoryReportRequest.h>
#elif __has_include("PLHistoryReportRequest.h")
   #import "PLHistoryReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLSafSummaryReportRequest.h>)
   #import <POSLinkAdmin/PLSafSummaryReportRequest.h>
#elif __has_include("PLSafSummaryReportRequest.h")
   #import "PLSafSummaryReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalFailedReportRequest.h>)
   #import <POSLinkAdmin/PLLocalFailedReportRequest.h>
#elif __has_include("PLLocalFailedReportRequest.h")
   #import "PLLocalFailedReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalDetailReportRequest.h>)
   #import <POSLinkAdmin/PLLocalDetailReportRequest.h>
#elif __has_include("PLLocalDetailReportRequest.h")
   #import "PLLocalDetailReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLHostDetailReportRequest.h>)
   #import <POSLinkAdmin/PLHostDetailReportRequest.h>
#elif __has_include("PLHostDetailReportRequest.h")
   #import "PLHostDetailReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalTotalReportRequest.h>)
   #import <POSLinkAdmin/PLLocalTotalReportRequest.h>
#elif __has_include("PLLocalTotalReportRequest.h")
   #import "PLLocalTotalReportRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetBatchHistoryListRequest.h>)
   #import <POSLinkAdmin/PLGetBatchHistoryListRequest.h>
#elif __has_include("PLGetBatchHistoryListRequest.h")
   #import "PLGetBatchHistoryListRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalDetailReportResponse.h>)
   #import <POSLinkAdmin/PLLocalDetailReportResponse.h>
#elif __has_include("PLLocalDetailReportResponse.h")
   #import "PLLocalDetailReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLSafSummaryReportResponse.h>)
   #import <POSLinkAdmin/PLSafSummaryReportResponse.h>
#elif __has_include("PLSafSummaryReportResponse.h")
   #import "PLSafSummaryReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLHistoryReportResponse.h>)
   #import <POSLinkAdmin/PLHistoryReportResponse.h>
#elif __has_include("PLHistoryReportResponse.h")
   #import "PLHistoryReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalTotalReportResponse.h>)
   #import <POSLinkAdmin/PLLocalTotalReportResponse.h>
#elif __has_include("PLLocalTotalReportResponse.h")
   #import "PLLocalTotalReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetBatchHistoryListResponse.h>)
   #import <POSLinkAdmin/PLGetBatchHistoryListResponse.h>
#elif __has_include("PLGetBatchHistoryListResponse.h")
   #import "PLGetBatchHistoryListResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLLocalFailedReportResponse.h>)
   #import <POSLinkAdmin/PLLocalFailedReportResponse.h>
#elif __has_include("PLLocalFailedReportResponse.h")
   #import "PLLocalFailedReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLHostDetailReportResponse.h>)
   #import <POSLinkAdmin/PLHostDetailReportResponse.h>
#elif __has_include("PLHostDetailReportResponse.h")
   #import "PLHostDetailReportResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLHostReportResponse.h>)
   #import <POSLinkAdmin/PLHostReportResponse.h>
#elif __has_include("PLHostReportResponse.h")
   #import "PLHostReportResponse.h"
#endif




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

/**
 * Get Batch History List Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getBatchHistoryListWithRequest:(PLGetBatchHistoryListRequest *)request completion:(void(^)(PLGetBatchHistoryListResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

