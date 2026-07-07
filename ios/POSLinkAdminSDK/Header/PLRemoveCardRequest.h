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
 Remove Card Request
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


#if __has_include(<POSLinkAdmin/PLRemoveCardRequest.h>)
   #import <POSLinkAdmin/PLRemoveCardRequest.h>
#elif __has_include("PLRemoveCardRequest.h")
   #import "PLRemoveCardRequest.h"
#endif



@interface PLRemoveCardRequest : PLRequest
/**
 Default message is "Please remove card".

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *message1;
/**
 Default message is NULL.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *message2;
/**
 Continuous screen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;
/**
 Pinpad type. Default is "InternalPinpad". "ExternalPinpad" and "ExternalPinpadFirst" are for A80 only. If used on another device, it will return param error.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum PinpadType pinpadType;
/**
 This field indicates which icon will be displayed on screen.

It could be following values:

"Icon_rmc_info": Info. A blue info mark icon will be displayed. (Default)

"Icon_rmc_approve": Approved. A green check mark icon will be displayed.

"Icon_rmc_decline": Decline. A red exclamation mark icon will be displayed.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *icon;


@end