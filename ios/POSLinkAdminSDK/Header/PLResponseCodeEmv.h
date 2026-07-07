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
 Response Code for EMV.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLEmvCode100003.h>)
   #import <POSLinkAdmin/PLEmvCode100003.h>
#elif __has_include("PLEmvCode100003.h")
   #import "PLEmvCode100003.h"
#endif


#if __has_include(<POSLinkAdmin/PLResponseCodeEmv.h>)
   #import <POSLinkAdmin/PLResponseCodeEmv.h>
#elif __has_include("PLResponseCodeEmv.h")
   #import "PLResponseCodeEmv.h"
#endif



@interface PLResponseCodeEmv : NSObject
/**
 Error code 100003. 
 */
@property (readwrite, nonatomic, strong)PLEmvCode100003 *code100003;

@end