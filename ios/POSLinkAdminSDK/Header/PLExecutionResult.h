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

NS_ASSUME_NONNULL_BEGIN

@interface PLExecutionResult : NSObject

/**
  isSuccessful\n
  true：successfully\n
  false：unsuccessfully\n
*/
@property (nonatomic, assign) BOOL isSuccessful;

/**
 * Result message of protocol communication See POSLinkErrorMsg.h
*/
@property (nonatomic, strong)NSString *responseMessage;

@end

NS_ASSUME_NONNULL_END
