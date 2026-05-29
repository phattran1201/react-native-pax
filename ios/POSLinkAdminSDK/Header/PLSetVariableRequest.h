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
 Set Variable Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLMultiMerchant.h"
#import "PLSetVariableRequest.h"

@interface PLSetVariableRequest : PLRequest
/**
 EDC Type 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 The name of the variable

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName1;
/**
 The value of the variable

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue1;
/**
 The name of the variable

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName2;
/**
 The value of the variable

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue2;
/**
 The name of the variable

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName3;
/**
 The value of the variable

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue3;
/**
 The name of the variable

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName4;
/**
 The value of the variable

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue4;
/**
 The name of the variable

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *variableName5;
/**
 The value of the variable

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *variableValue5;
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;


@end