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
 Set Google Smart Tap Parameters Request
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


#if __has_include(<POSLinkAdmin/PLGoogleServiceTypeBitmap.h>)
   #import <POSLinkAdmin/PLGoogleServiceTypeBitmap.h>
#elif __has_include("PLGoogleServiceTypeBitmap.h")
   #import "PLGoogleServiceTypeBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLGoogleSmartTapCapBitmap.h>)
   #import <POSLinkAdmin/PLGoogleSmartTapCapBitmap.h>
#elif __has_include("PLGoogleSmartTapCapBitmap.h")
   #import "PLGoogleSmartTapCapBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLGoogleSmartTap.h>)
   #import <POSLinkAdmin/PLGoogleSmartTap.h>
#elif __has_include("PLGoogleSmartTap.h")
   #import "PLGoogleSmartTap.h"
#endif


#if __has_include(<POSLinkAdmin/PLSetGoogleSmartTapParametersRequest.h>)
   #import <POSLinkAdmin/PLSetGoogleSmartTapParametersRequest.h>
#elif __has_include("PLSetGoogleSmartTapParametersRequest.h")
   #import "PLSetGoogleSmartTapParametersRequest.h"
#endif



@interface PLSetGoogleSmartTapParametersRequest : PLRequest
/**
 VAS mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum VasMode vasMode;
/**
 Google Smart Tap specific data. 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTap *googleSmartTapData;


@end