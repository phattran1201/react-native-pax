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
 Request AVS information.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAvsRequest.h>)
   #import <POSLinkAdmin/PLAvsRequest.h>
#elif __has_include("PLAvsRequest.h")
   #import "PLAvsRequest.h"
#endif



@interface PLAvsRequest : NSObject
/**
 The zip code of the cardholder. The application supports 5 to 9 characters including number, letters, and space.

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *zipCode;
/**
 The primary address of the cardholder. The actual maximum length is host-dependent but may not exceed 32 characters.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address;
/**
 The secondary address of the cardholder. The actual maximum length is host-dependent but may not exceed 32 characters.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address2;

@end