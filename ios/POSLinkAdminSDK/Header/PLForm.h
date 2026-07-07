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



#if __has_include(<POSLinkAdmin/PLShowMessageCenterRequest.h>)
   #import <POSLinkAdmin/PLShowMessageCenterRequest.h>
#elif __has_include("PLShowMessageCenterRequest.h")
   #import "PLShowMessageCenterRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLInputTextRequest.h>)
   #import <POSLinkAdmin/PLInputTextRequest.h>
#elif __has_include("PLInputTextRequest.h")
   #import "PLInputTextRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLClearMessageRequest.h>)
   #import <POSLinkAdmin/PLClearMessageRequest.h>
#elif __has_include("PLClearMessageRequest.h")
   #import "PLClearMessageRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowItemRequest.h>)
   #import <POSLinkAdmin/PLShowItemRequest.h>
#elif __has_include("PLShowItemRequest.h")
   #import "PLShowItemRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowMessageRequest.h>)
   #import <POSLinkAdmin/PLShowMessageRequest.h>
#elif __has_include("PLShowMessageRequest.h")
   #import "PLShowMessageRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowDialogRequest.h>)
   #import <POSLinkAdmin/PLShowDialogRequest.h>
#elif __has_include("PLShowDialogRequest.h")
   #import "PLShowDialogRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowTextBoxRequest.h>)
   #import <POSLinkAdmin/PLShowTextBoxRequest.h>
#elif __has_include("PLShowTextBoxRequest.h")
   #import "PLShowTextBoxRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowDialogFormRequest.h>)
   #import <POSLinkAdmin/PLShowDialogFormRequest.h>
#elif __has_include("PLShowDialogFormRequest.h")
   #import "PLShowDialogFormRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLRemoveCardRequest.h>)
   #import <POSLinkAdmin/PLRemoveCardRequest.h>
#elif __has_include("PLRemoveCardRequest.h")
   #import "PLRemoveCardRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowTextBoxResponse.h>)
   #import <POSLinkAdmin/PLShowTextBoxResponse.h>
#elif __has_include("PLShowTextBoxResponse.h")
   #import "PLShowTextBoxResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowItemResponse.h>)
   #import <POSLinkAdmin/PLShowItemResponse.h>
#elif __has_include("PLShowItemResponse.h")
   #import "PLShowItemResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowMessageResponse.h>)
   #import <POSLinkAdmin/PLShowMessageResponse.h>
#elif __has_include("PLShowMessageResponse.h")
   #import "PLShowMessageResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowDialogResponse.h>)
   #import <POSLinkAdmin/PLShowDialogResponse.h>
#elif __has_include("PLShowDialogResponse.h")
   #import "PLShowDialogResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowDialogFormResponse.h>)
   #import <POSLinkAdmin/PLShowDialogFormResponse.h>
#elif __has_include("PLShowDialogFormResponse.h")
   #import "PLShowDialogFormResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLRemoveCardResponse.h>)
   #import <POSLinkAdmin/PLRemoveCardResponse.h>
#elif __has_include("PLRemoveCardResponse.h")
   #import "PLRemoveCardResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLInputTextResponse.h>)
   #import <POSLinkAdmin/PLInputTextResponse.h>
#elif __has_include("PLInputTextResponse.h")
   #import "PLInputTextResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLClearMessageResponse.h>)
   #import <POSLinkAdmin/PLClearMessageResponse.h>
#elif __has_include("PLClearMessageResponse.h")
   #import "PLClearMessageResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLShowMessageCenterResponse.h>)
   #import <POSLinkAdmin/PLShowMessageCenterResponse.h>
#elif __has_include("PLShowMessageCenterResponse.h")
   #import "PLShowMessageCenterResponse.h"
#endif




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

