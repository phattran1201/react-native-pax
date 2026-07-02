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
 Show Msg Center Aligned Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLShowMessageCenterResponse.h>)
   #import <POSLinkAdmin/PLShowMessageCenterResponse.h>
#elif __has_include("PLShowMessageCenterResponse.h")
   #import "PLShowMessageCenterResponse.h"
#endif



@interface PLShowMessageCenterResponse : PLResponse
/**
 Pinpad type. Only support InternalPinpad and ExternalPinpad.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum PinpadType pinpadType;


@end