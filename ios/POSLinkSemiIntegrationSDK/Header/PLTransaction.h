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



#if __has_include(<POSLinkAdmin/PLDoLoyaltyRequest.h>)
   #import <POSLinkAdmin/PLDoLoyaltyRequest.h>
#elif __has_include("PLDoLoyaltyRequest.h")
   #import "PLDoLoyaltyRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoEbtRequest.h>)
   #import <POSLinkAdmin/PLDoEbtRequest.h>
#elif __has_include("PLDoEbtRequest.h")
   #import "PLDoEbtRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoDebitRequest.h>)
   #import <POSLinkAdmin/PLDoDebitRequest.h>
#elif __has_include("PLDoDebitRequest.h")
   #import "PLDoDebitRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoCashRequest.h>)
   #import <POSLinkAdmin/PLDoCashRequest.h>
#elif __has_include("PLDoCashRequest.h")
   #import "PLDoCashRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetCardInformationRequest.h>)
   #import <POSLinkAdmin/PLGetCardInformationRequest.h>
#elif __has_include("PLGetCardInformationRequest.h")
   #import "PLGetCardInformationRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoQrPaymentRequest.h>)
   #import <POSLinkAdmin/PLDoQrPaymentRequest.h>
#elif __has_include("PLDoQrPaymentRequest.h")
   #import "PLDoQrPaymentRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoCreditRequest.h>)
   #import <POSLinkAdmin/PLDoCreditRequest.h>
#elif __has_include("PLDoCreditRequest.h")
   #import "PLDoCreditRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoGiftRequest.h>)
   #import <POSLinkAdmin/PLDoGiftRequest.h>
#elif __has_include("PLDoGiftRequest.h")
   #import "PLDoGiftRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoQrPaymentResponse.h>)
   #import <POSLinkAdmin/PLDoQrPaymentResponse.h>
#elif __has_include("PLDoQrPaymentResponse.h")
   #import "PLDoQrPaymentResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetCardInformationResponse.h>)
   #import <POSLinkAdmin/PLGetCardInformationResponse.h>
#elif __has_include("PLGetCardInformationResponse.h")
   #import "PLGetCardInformationResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoCashResponse.h>)
   #import <POSLinkAdmin/PLDoCashResponse.h>
#elif __has_include("PLDoCashResponse.h")
   #import "PLDoCashResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoEbtResponse.h>)
   #import <POSLinkAdmin/PLDoEbtResponse.h>
#elif __has_include("PLDoEbtResponse.h")
   #import "PLDoEbtResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoLoyaltyResponse.h>)
   #import <POSLinkAdmin/PLDoLoyaltyResponse.h>
#elif __has_include("PLDoLoyaltyResponse.h")
   #import "PLDoLoyaltyResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoDebitResponse.h>)
   #import <POSLinkAdmin/PLDoDebitResponse.h>
#elif __has_include("PLDoDebitResponse.h")
   #import "PLDoDebitResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoCreditResponse.h>)
   #import <POSLinkAdmin/PLDoCreditResponse.h>
#elif __has_include("PLDoCreditResponse.h")
   #import "PLDoCreditResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLDoGiftResponse.h>)
   #import <POSLinkAdmin/PLDoGiftResponse.h>
#elif __has_include("PLDoGiftResponse.h")
   #import "PLDoGiftResponse.h"
#endif




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
 * Get card information request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getCardInformationWithRequest:(PLGetCardInformationRequest *)request completion:(void(^)(PLGetCardInformationResponse *response,PLExecutionResult *result))completion;

/**
 * Do QR payment request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doQrPaymentWithRequest:(PLDoQrPaymentRequest *)request completion:(void(^)(PLDoQrPaymentResponse *response,PLExecutionResult *result))completion;

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

