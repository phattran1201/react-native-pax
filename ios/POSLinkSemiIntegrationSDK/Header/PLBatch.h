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



#if __has_include(<POSLinkAdmin/PLBatchClearRequest.h>)
   #import <POSLinkAdmin/PLBatchClearRequest.h>
#elif __has_include("PLBatchClearRequest.h")
   #import "PLBatchClearRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLForceBatchCloseRequest.h>)
   #import <POSLinkAdmin/PLForceBatchCloseRequest.h>
#elif __has_include("PLForceBatchCloseRequest.h")
   #import "PLForceBatchCloseRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLBatchCloseRequest.h>)
   #import <POSLinkAdmin/PLBatchCloseRequest.h>
#elif __has_include("PLBatchCloseRequest.h")
   #import "PLBatchCloseRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDeleteTransactionRequest.h>)
   #import <POSLinkAdmin/PLDeleteTransactionRequest.h>
#elif __has_include("PLDeleteTransactionRequest.h")
   #import "PLDeleteTransactionRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLSafUploadRequest.h>)
   #import <POSLinkAdmin/PLSafUploadRequest.h>
#elif __has_include("PLSafUploadRequest.h")
   #import "PLSafUploadRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDeleteSafFileRequest.h>)
   #import <POSLinkAdmin/PLDeleteSafFileRequest.h>
#elif __has_include("PLDeleteSafFileRequest.h")
   #import "PLDeleteSafFileRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLForceBatchCloseResponse.h>)
   #import <POSLinkAdmin/PLForceBatchCloseResponse.h>
#elif __has_include("PLForceBatchCloseResponse.h")
   #import "PLForceBatchCloseResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDeleteSafFileResponse.h>)
   #import <POSLinkAdmin/PLDeleteSafFileResponse.h>
#elif __has_include("PLDeleteSafFileResponse.h")
   #import "PLDeleteSafFileResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLBatchClearResponse.h>)
   #import <POSLinkAdmin/PLBatchClearResponse.h>
#elif __has_include("PLBatchClearResponse.h")
   #import "PLBatchClearResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLBatchCloseResponse.h>)
   #import <POSLinkAdmin/PLBatchCloseResponse.h>
#elif __has_include("PLBatchCloseResponse.h")
   #import "PLBatchCloseResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDeleteTransactionResponse.h>)
   #import <POSLinkAdmin/PLDeleteTransactionResponse.h>
#elif __has_include("PLDeleteTransactionResponse.h")
   #import "PLDeleteTransactionResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLSafUploadResponse.h>)
   #import <POSLinkAdmin/PLSafUploadResponse.h>
#elif __has_include("PLSafUploadResponse.h")
   #import "PLSafUploadResponse.h"
#endif




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
 * Force the batch to clear or close as a last resort when the current batch cannot be closed.
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

