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



#if __has_include(<POSLinkAdmin/PLCustomDataEncryptionRequest.h>)
   #import <POSLinkAdmin/PLCustomDataEncryptionRequest.h>
#elif __has_include("PLCustomDataEncryptionRequest.h")
   #import "PLCustomDataEncryptionRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetPedInformationRequest.h>)
   #import <POSLinkAdmin/PLGetPedInformationRequest.h>
#elif __has_include("PLGetPedInformationRequest.h")
   #import "PLGetPedInformationRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLIncreaseKsnRequest.h>)
   #import <POSLinkAdmin/PLIncreaseKsnRequest.h>
#elif __has_include("PLIncreaseKsnRequest.h")
   #import "PLIncreaseKsnRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLSessionKeyInjectionRequest.h>)
   #import <POSLinkAdmin/PLSessionKeyInjectionRequest.h>
#elif __has_include("PLSessionKeyInjectionRequest.h")
   #import "PLSessionKeyInjectionRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLMacCalculationRequest.h>)
   #import <POSLinkAdmin/PLMacCalculationRequest.h>
#elif __has_include("PLMacCalculationRequest.h")
   #import "PLMacCalculationRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLIncreaseKsnResponse.h>)
   #import <POSLinkAdmin/PLIncreaseKsnResponse.h>
#elif __has_include("PLIncreaseKsnResponse.h")
   #import "PLIncreaseKsnResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLSessionKeyInjectionResponse.h>)
   #import <POSLinkAdmin/PLSessionKeyInjectionResponse.h>
#elif __has_include("PLSessionKeyInjectionResponse.h")
   #import "PLSessionKeyInjectionResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLMacCalculationResponse.h>)
   #import <POSLinkAdmin/PLMacCalculationResponse.h>
#elif __has_include("PLMacCalculationResponse.h")
   #import "PLMacCalculationResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLGetPedInformationResponse.h>)
   #import <POSLinkAdmin/PLGetPedInformationResponse.h>
#elif __has_include("PLGetPedInformationResponse.h")
   #import "PLGetPedInformationResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLCustomDataEncryptionResponse.h>)
   #import <POSLinkAdmin/PLCustomDataEncryptionResponse.h>
#elif __has_include("PLCustomDataEncryptionResponse.h")
   #import "PLCustomDataEncryptionResponse.h"
#endif




NS_ASSUME_NONNULL_BEGIN

@interface PLPed : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Custom Data Encryption Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)customDataEncryptionWithRequest:(PLCustomDataEncryptionRequest *)request completion:(void(^)(PLCustomDataEncryptionResponse *response,PLExecutionResult *result))completion;

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

