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
 Remove Card Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLRemoveCardRequest.h"

@interface PLRemoveCardRequest : PLRequest
/**
 Default message is "Please remove card".

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *message1;
/**
 Default message is NULL.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *message2;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;
/**
 Pinpad type. Defalut is "InternalPinpad". "ExternalPinpad" and "ExternalPinpadFirst" is A80 only, if use other device will return param error. 
 */
@property (readwrite, nonatomic, assign)enum PinpadType pinpadType;


@end