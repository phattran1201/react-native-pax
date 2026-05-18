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
#import "PLDeleteImageRequest.h"
#import "PLDoSignatureRequest.h"
#import "PLVasPushDataRequest.h"
#import "PLTokenAdministrativeRequest.h"
#import "PLResetMsrRequest.h"
#import "PLInitRequest.h"
#import "PLSetGoogleSmartTapParametersRequest.h"
#import "PLCheckFileRequest.h"
#import "PLResetRequest.h"
#import "PLSetSafParametersRequest.h"
#import "PLSetApplePayVasParametersRequest.h"
#import "PLGetSafParametersRequest.h"
#import "PLGetSignatureRequest.h"
#import "PLGetVariableRequest.h"
#import "PLReprintRequest.h"
#import "PLUpdateResourceFileRequest.h"
#import "PLInputAccountRequest.h"
#import "PLRebootRequest.h"
#import "PLSetVariableRequest.h"
#import "PLSetVariableResponse.h"
#import "PLInputAccountResponse.h"
#import "PLSetSafParametersResponse.h"
#import "PLSetApplePayVasParametersResponse.h"
#import "PLUpdateResourceFileResponse.h"
#import "PLResetMsrResponse.h"
#import "PLReprintResponse.h"
#import "PLResetResponse.h"
#import "PLGetSignatureResponse.h"
#import "PLGetSafParametersResponse.h"
#import "PLInitResponse.h"
#import "PLCheckFileResponse.h"
#import "PLTokenAdministrativeResponse.h"
#import "PLDoSignatureResponse.h"
#import "PLVasPushDataResponse.h"
#import "PLDeleteImageResponse.h"
#import "PLRebootResponse.h"
#import "PLGetVariableResponse.h"
#import "PLSetGoogleSmartTapParametersResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLManage : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Delete Image Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)deleteImageWithRequest:(PLDeleteImageRequest *)request completion:(void(^)(PLDeleteImageResponse *response,PLExecutionResult *result))completion;

/**
 * Do Signature Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)doSignatureWithRequest:(PLDoSignatureRequest *)request completion:(void(^)(PLDoSignatureResponse *response,PLExecutionResult *result))completion;

/**
 * Vas Push Data Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)vasPushDataWithRequest:(PLVasPushDataRequest *)request completion:(void(^)(PLVasPushDataResponse *response,PLExecutionResult *result))completion;

/**
 * Token Administrative Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)tokenAdministrativeWithRequest:(PLTokenAdministrativeRequest *)request completion:(void(^)(PLTokenAdministrativeResponse *response,PLExecutionResult *result))completion;

/**
 * Reset MSR Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)resetMsrWithRequest:(PLResetMsrRequest *)request completion:(void(^)(PLResetMsrResponse *response,PLExecutionResult *result))completion;

/**
 * Init Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)initWithRequest:(PLInitRequest *)request completion:(void(^)(PLInitResponse *response,PLExecutionResult *result))completion;

/**
 * Set Google Smart Tap Parameters Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)setGoogleSmartTapParametersWithRequest:(PLSetGoogleSmartTapParametersRequest *)request completion:(void(^)(PLSetGoogleSmartTapParametersResponse *response,PLExecutionResult *result))completion;

/**
 * Check File Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)checkFileWithRequest:(PLCheckFileRequest *)request completion:(void(^)(PLCheckFileResponse *response,PLExecutionResult *result))completion;

/**
 * Reset Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)resetWithRequest:(PLResetRequest *)request completion:(void(^)(PLResetResponse *response,PLExecutionResult *result))completion;

/**
 * Set SAF Parameters Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)setSafParametersWithRequest:(PLSetSafParametersRequest *)request completion:(void(^)(PLSetSafParametersResponse *response,PLExecutionResult *result))completion;

/**
 * Set Apple Pay VAS Parameters Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)setApplePayVasParametersWithRequest:(PLSetApplePayVasParametersRequest *)request completion:(void(^)(PLSetApplePayVasParametersResponse *response,PLExecutionResult *result))completion;

/**
 * Get SAF Parameters Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getSafParametersWithRequest:(PLGetSafParametersRequest *)request completion:(void(^)(PLGetSafParametersResponse *response,PLExecutionResult *result))completion;

/**
 * Get Signature Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getSignatureWithRequest:(PLGetSignatureRequest *)request completion:(void(^)(PLGetSignatureResponse *response,PLExecutionResult *result))completion;

/**
 * Get Variable Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)getVariableWithRequest:(PLGetVariableRequest *)request completion:(void(^)(PLGetVariableResponse *response,PLExecutionResult *result))completion;

/**
 * Reprint Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)reprintWithRequest:(PLReprintRequest *)request completion:(void(^)(PLReprintResponse *response,PLExecutionResult *result))completion;

/**
 * Update Resource File Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)updateResourceFileWithRequest:(PLUpdateResourceFileRequest *)request completion:(void(^)(PLUpdateResourceFileResponse *response,PLExecutionResult *result))completion;

/**
 * Input Account Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)inputAccountWithRequest:(PLInputAccountRequest *)request completion:(void(^)(PLInputAccountResponse *response,PLExecutionResult *result))completion;

/**
 * Reboot Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)rebootWithRequest:(PLRebootRequest *)request completion:(void(^)(PLRebootResponse *response,PLExecutionResult *result))completion;

/**
 * Set Variable Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)setVariableWithRequest:(PLSetVariableRequest *)request completion:(void(^)(PLSetVariableResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

