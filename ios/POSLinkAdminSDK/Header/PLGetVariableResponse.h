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
 Get Variable Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLMultiMerchant.h>)
   #import <POSLinkAdmin/PLMultiMerchant.h>
#elif __has_include("PLMultiMerchant.h")
   #import "PLMultiMerchant.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetVariableResponse.h>)
   #import <POSLinkAdmin/PLGetVariableResponse.h>
#elif __has_include("PLGetVariableResponse.h")
   #import "PLGetVariableResponse.h"
#endif



@interface PLGetVariableResponse : PLResponse
/**
 The value of the variable, if the value exists, this field is mandatory.

 Attribute : ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue1;
/**
 The value of the variable, if the value exists, this field is mandatory.

 Attribute : ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue2;
/**
 The value of the variable, if the value exists, this field is mandatory.

 Attribute : ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue3;
/**
 The value of the variable, if the value exists, this field is mandatory.

 Attribute : ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue4;
/**
 The value of the variable, if the value exists, this field is mandatory.

 Attribute : ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue5;
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;


@end