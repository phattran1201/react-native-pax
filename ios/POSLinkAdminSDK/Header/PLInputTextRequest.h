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
 Input Text Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLInputTextRequest.h"

@interface PLInputTextRequest : PLRequest
/**
 The title that to be displayed. 
 */
@property (readwrite, nonatomic, assign)enum InputTextPrompt title;
/**
 Input type. Default is AlphaNumeric. 
 */
@property (readwrite, nonatomic, assign)enum InputType inputType;
/**
 MIN length. Default to 0. Valid value [0, 32].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *minLength;
/**
 MAX length. Default to 32. Valid value [1, 32].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *maxLength;
/**
 Default input value. Valid if "InputType" is 0 or 1.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *defaultValue;
/**
 Timeout in 100ms for waiting text input. Valid value should be [1, 9999]. The value of "" means waiting till user canceled or confirmed.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end