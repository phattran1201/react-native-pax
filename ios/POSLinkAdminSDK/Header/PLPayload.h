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



#if __has_include(<POSLinkAdmin/PLPayloadRequest.h>)
   #import <POSLinkAdmin/PLPayloadRequest.h>
#elif __has_include("PLPayloadRequest.h")
   #import "PLPayloadRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLPayloadResponse.h>)
   #import <POSLinkAdmin/PLPayloadResponse.h>
#elif __has_include("PLPayloadResponse.h")
   #import "PLPayloadResponse.h"
#endif




NS_ASSUME_NONNULL_BEGIN

@interface PLPayload : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Payload request.
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)payloadWithRequest:(PLPayloadRequest *)request completion:(void(^)(PLPayloadResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

