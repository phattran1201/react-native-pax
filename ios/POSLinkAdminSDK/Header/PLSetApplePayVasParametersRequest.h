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
/**
 Set Apple Pay VAS Parameters Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLApplePayVas.h"
#import "PLSetApplePayVasParametersRequest.h"

@interface PLSetApplePayVasParametersRequest : PLRequest
/**
 VAS mode. 
 */
@property (readwrite, nonatomic, assign)enum VasMode vasMode;
/**
 Apple Pay VAS specific data. 
 */
@property (readwrite, nonatomic, strong)PLApplePayVas *applePayVasData;


@end