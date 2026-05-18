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
#import "PLBatchClearRequest.h"
#import "PLPurgeBatchRequest.h"
#import "PLForceBatchCloseRequest.h"
#import "PLBatchCloseRequest.h"
#import "PLDeleteTransactionRequest.h"
#import "PLSafUploadRequest.h"
#import "PLDeleteSafFileRequest.h"
#import "PLForceBatchCloseResponse.h"
#import "PLDeleteSafFileResponse.h"
#import "PLBatchClearResponse.h"
#import "PLPurgeBatchResponse.h"
#import "PLBatchCloseResponse.h"
#import "PLDeleteTransactionResponse.h"
#import "PLSafUploadResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLBatch : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Batch Clear Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)batchClearWithRequest:(PLBatchClearRequest *)request completion:(void(^)(PLBatchClearResponse *response,PLExecutionResult *result))completion;

/**
 * Purge Batch Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)purgeBatchWithRequest:(PLPurgeBatchRequest *)request completion:(void(^)(PLPurgeBatchResponse *response,PLExecutionResult *result))completion;

/**
 * Force Batch Close Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)forceBatchCloseWithRequest:(PLForceBatchCloseRequest *)request completion:(void(^)(PLForceBatchCloseResponse *response,PLExecutionResult *result))completion;

/**
 * Batch Close Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)batchCloseWithRequest:(PLBatchCloseRequest *)request completion:(void(^)(PLBatchCloseResponse *response,PLExecutionResult *result))completion;

/**
 * Delete Transaction Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)deleteTransactionWithRequest:(PLDeleteTransactionRequest *)request completion:(void(^)(PLDeleteTransactionResponse *response,PLExecutionResult *result))completion;

/**
 * SAF Upload Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)safUploadWithRequest:(PLSafUploadRequest *)request completion:(void(^)(PLSafUploadResponse *response,PLExecutionResult *result))completion;

/**
 * Delete SAF File Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)deleteSafFileWithRequest:(PLDeleteSafFileRequest *)request completion:(void(^)(PLDeleteSafFileResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

