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
 Error code 100014
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100014.h>)
   #import <POSLinkAdmin/PLCode100014.h>
#elif __has_include("PLCode100014.h")
   #import "PLCode100014.h"
#endif



@interface PLCode100014 : NSObject
/**
 Set variable error 
 */
@property (readwrite, nonatomic, copy)NSString *setVarError;
/**
 The value of variable is not legal. 
 */
@property (readwrite, nonatomic, copy)NSString *invalidVarValue;
/**
 The variable value is null. 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseSetVar;
/**
 Invalid data entry 
 */
@property (readwrite, nonatomic, copy)NSString *invalidDataEntry;

@end