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
#import "PLShowMessageCenterRequest.h"
#import "PLInputTextRequest.h"
#import "PLClearMessageRequest.h"
#import "PLShowItemRequest.h"
#import "PLShowMessageRequest.h"
#import "PLShowDialogRequest.h"
#import "PLShowTextBoxRequest.h"
#import "PLShowDialogFormRequest.h"
#import "PLRemoveCardRequest.h"
#import "PLShowTextBoxResponse.h"
#import "PLShowItemResponse.h"
#import "PLShowMessageResponse.h"
#import "PLShowDialogResponse.h"
#import "PLShowDialogFormResponse.h"
#import "PLRemoveCardResponse.h"
#import "PLInputTextResponse.h"
#import "PLClearMessageResponse.h"
#import "PLShowMessageCenterResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLForm : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Show Msg Center Aligned Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showMessageCenterWithRequest:(PLShowMessageCenterRequest *)request completion:(void(^)(PLShowMessageCenterResponse *response,PLExecutionResult *result))completion;

/**
 * Input Text Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)inputTextWithRequest:(PLInputTextRequest *)request completion:(void(^)(PLInputTextResponse *response,PLExecutionResult *result))completion;

/**
 * Clear Message Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)clearMessageWithRequest:(PLClearMessageRequest *)request completion:(void(^)(PLClearMessageResponse *response,PLExecutionResult *result))completion;

/**
 * Show Item Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showItemWithRequest:(PLShowItemRequest *)request completion:(void(^)(PLShowItemResponse *response,PLExecutionResult *result))completion;

/**
 * Show Message Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showMessageWithRequest:(PLShowMessageRequest *)request completion:(void(^)(PLShowMessageResponse *response,PLExecutionResult *result))completion;

/**
 * Show Dialog Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showDialogWithRequest:(PLShowDialogRequest *)request completion:(void(^)(PLShowDialogResponse *response,PLExecutionResult *result))completion;

/**
 * Show Text Box Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showTextBoxWithRequest:(PLShowTextBoxRequest *)request completion:(void(^)(PLShowTextBoxResponse *response,PLExecutionResult *result))completion;

/**
 * Show Dialog Form Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)showDialogFormWithRequest:(PLShowDialogFormRequest *)request completion:(void(^)(PLShowDialogFormResponse *response,PLExecutionResult *result))completion;

/**
 * Remove Card Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)removeCardWithRequest:(PLRemoveCardRequest *)request completion:(void(^)(PLRemoveCardResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

