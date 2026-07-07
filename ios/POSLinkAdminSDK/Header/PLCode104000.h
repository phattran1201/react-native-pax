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
 Error code 104000
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode104000.h>)
   #import <POSLinkAdmin/PLCode104000.h>
#elif __has_include("PLCode104000.h")
   #import "PLCode104000.h"
#endif



@interface PLCode104000 : NSObject
/**
 Location access denied, unable to initialize Dual SIM failover function. 
 */
@property (readwrite, nonatomic, copy)NSString *locationAccessDenied;
/**
 Device Call Access Denied, unable to initialize Dual SIM failover function. 
 */
@property (readwrite, nonatomic, copy)NSString *deviceCallAccessDenied;

@end