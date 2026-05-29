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
 Show Text Box Button Properties.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLStbButton.h"

@interface PLStbButton : NSObject
/**
 The name of button on terminal

 Attribute:ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *name;
/**
 Please use the hexadecimal to represent the color. For example, ffffff which represent the white color. 00ff00 which means the green color. If this value not to be set, the default value will be used.

 Attribute:ans6 
 */
@property (readwrite, nonatomic, copy)NSString *color;
/**
 The hard key to be mapped for Button. 
 */
@property (readwrite, nonatomic, assign)enum HardKey hardKey;

@end