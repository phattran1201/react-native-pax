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
#import "PLGetPedInformationRequest.h"
#import "PLIncreaseKsnRequest.h"
#import "PLSessionKeyInjectionRequest.h"
#import "PLMacCalculationRequest.h"
#import "PLIncreaseKsnResponse.h"
#import "PLSessionKeyInjectionResponse.h"
#import "PLMacCalculationResponse.h"
#import "PLGetPedInformationResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLPed : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Get PED information request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getPedInformationWithRequest:(PLGetPedInformationRequest *)request completion:(void(^)(PLGetPedInformationResponse *response,PLExecutionResult *result))completion;

/**
 * Increase KSN request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)increaseKsnWithRequest:(PLIncreaseKsnRequest *)request completion:(void(^)(PLIncreaseKsnResponse *response,PLExecutionResult *result))completion;

/**
 * Session key injection request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)sessionKeyInjectionWithRequest:(PLSessionKeyInjectionRequest *)request completion:(void(^)(PLSessionKeyInjectionResponse *response,PLExecutionResult *result))completion;

/**
 * MAC calculation request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)macCalculationWithRequest:(PLMacCalculationRequest *)request completion:(void(^)(PLMacCalculationResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

