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
 New Service
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLNewService.h>)
   #import <POSLinkAdmin/PLNewService.h>
#elif __has_include("PLNewService.h")
   #import "PLNewService.h"
#endif



@interface PLNewService : NSObject
/**
 New services type.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum NewServiceType type;
/**
 Title of the new service

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 An endpoint where the user may access the new service

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *url;

@end