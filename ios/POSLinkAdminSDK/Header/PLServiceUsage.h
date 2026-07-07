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
 Service Usage class
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLServiceUsage.h>)
   #import <POSLinkAdmin/PLServiceUsage.h>
#elif __has_include("PLServiceUsage.h")
   #import "PLServiceUsage.h"
#endif



@interface PLServiceUsage : NSObject
/**
 Service usage ID

 Attribute : ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *usageId;
/**
 Service state.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ServiceState state;
/**
 A short description of valuables.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 Intended to be used to provide more context on how the valuable was used.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *describe;

@end