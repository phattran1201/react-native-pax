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
 Get Variable Request
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


#if __has_include(<POSLinkAdmin/PLMultiMerchant.h>)
   #import <POSLinkAdmin/PLMultiMerchant.h>
#elif __has_include("PLMultiMerchant.h")
   #import "PLMultiMerchant.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetVariableRequest.h>)
   #import <POSLinkAdmin/PLGetVariableRequest.h>
#elif __has_include("PLGetVariableRequest.h")
   #import "PLGetVariableRequest.h"
#endif



@interface PLGetVariableRequest : PLRequest
/**
 EdcType 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 The name of the variable.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName1;
/**
 The name of the variable.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName2;
/**
 The name of the variable.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName3;
/**
 The name of the variable.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName4;
/**
 The name of the variable.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName5;
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;


@end