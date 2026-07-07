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
 Response FPS Information.
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


#if __has_include(<POSLinkAdmin/PLFpsResponse.h>)
   #import <POSLinkAdmin/PLFpsResponse.h>
#elif __has_include("PLFpsResponse.h")
   #import "PLFpsResponse.h"
#endif



@interface PLFpsResponse : NSObject
/**
 1 means the transaction amount less that Authorization limit and trans is offline approved.

 Attribute : n1 
 */
@property (readwrite, nonatomic, copy)NSString *fps;
/**
 1 means the transaction amount less that Signature limit and no signature on receipt needed. And Signature on MT30 is also not needed.

 Attribute : n1 
 */
@property (readwrite, nonatomic, copy)NSString *fpsSignature;
/**
 FPS Receipt mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum FpsReceipt fpsReceipt;

@end