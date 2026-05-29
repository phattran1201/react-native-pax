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
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLMultiMerchant.h"
#import "PLGetVariableRequest.h"

@interface PLGetVariableRequest : PLRequest
/**
 EdcType 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 The name of the variable.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName1;
/**
 The name of the variable.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName2;
/**
 The name of the variable.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName3;
/**
 The name of the variable.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName4;
/**
 The name of the variable.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName5;
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;


@end