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
#import "PLDoLoyaltyRequest.h"
#import "PLDoEbtRequest.h"
#import "PLDoDebitRequest.h"
#import "PLDoCashRequest.h"
#import "PLDoCheckRequest.h"
#import "PLDoCreditRequest.h"
#import "PLDoGiftRequest.h"
#import "PLDoCashResponse.h"
#import "PLDoEbtResponse.h"
#import "PLDoLoyaltyResponse.h"
#import "PLDoDebitResponse.h"
#import "PLDoCheckResponse.h"
#import "PLDoCreditResponse.h"
#import "PLDoGiftResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLTransaction : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * This command is used to execute the loyalty payment method transactions. It uses the single transaction flow.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doLoyaltyWithRequest:(PLDoLoyaltyRequest *)request completion:(void(^)(PLDoLoyaltyResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the EBT payment method transactions. It uses the single transaction flow.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doEbtWithRequest:(PLDoEbtRequest *)request completion:(void(^)(PLDoEbtResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the debit payment method transactions. It uses the single transaction flow.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doDebitWithRequest:(PLDoDebitRequest *)request completion:(void(^)(PLDoDebitResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the cash payment method transactions.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doCashWithRequest:(PLDoCashRequest *)request completion:(void(^)(PLDoCashResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the check payment method transactions. It uses the single transaction flow.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doCheckWithRequest:(PLDoCheckRequest *)request completion:(void(^)(PLDoCheckResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the credit payment transactions when Auto EDC mode is disabled and will use the credit transaction flow. When Auto EDC is enabled, this command will be executed as do payment without specifying the EDC type, the EDC will be processed based on the card type.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doCreditWithRequest:(PLDoCreditRequest *)request completion:(void(^)(PLDoCreditResponse *response,PLExecutionResult *result))completion;

/**
 * This command is used to execute the gift payment method transactions. It uses the single transaction flow.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doGiftWithRequest:(PLDoGiftRequest *)request completion:(void(^)(PLDoGiftResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

