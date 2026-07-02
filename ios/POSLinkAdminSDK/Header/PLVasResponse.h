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
 Response VAS Information.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLVasResponse.h>)
   #import <POSLinkAdmin/PLVasResponse.h>
#elif __has_include("PLVasResponse.h")
   #import "PLVasResponse.h"
#endif



@interface PLVasResponse : NSObject
/**
 VAS response code.

 Attribute : n3 
 */
@property (readwrite, nonatomic, assign)enum VasResponseCode vasCode;
/**
 Tokens should be returned here.

 Attribute : var 
 */
@property (readwrite, nonatomic, copy)NSArray<NSString *> *vasData;
/**
 Google Smart Tap response data in format of NEDF, the message will be encoded with Base64.

 Attribute : ans...1024 
 */
@property (readwrite, nonatomic, copy)NSString *ndefData;

@end