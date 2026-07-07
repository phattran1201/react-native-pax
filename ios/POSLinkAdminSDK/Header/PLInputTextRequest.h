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
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLInputTextRequest.h>)
   #import <POSLinkAdmin/PLInputTextRequest.h>
#elif __has_include("PLInputTextRequest.h")
   #import "PLInputTextRequest.h"
#endif



@interface PLInputTextRequest : PLRequest
/**
 The title that will be displayed.

 Attribute : ans...36 
 */
@property (readwrite, nonatomic, assign)enum InputTextPrompt title;
/**
 Input type. Default is AlphaNumeric.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum InputType inputType;
/**
 MIN length. Default to 0. Valid value [0, 32].

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *minLength;
/**
 MAX length. Default to 32. Valid value [1, 32].

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *maxLength;
/**
 Default input value. Valid if "InputType" is 0 or 1.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *defaultValue;
/**
 Timeout in 100ms for waiting text input. Valid value should be [1, 9999]. The value of "" means waiting till user canceled or confirmed.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end