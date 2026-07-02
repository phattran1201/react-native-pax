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
 Response cashier information.
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


#if __has_include(<POSLinkAdmin/PLCashierResponse.h>)
   #import <POSLinkAdmin/PLCashierResponse.h>
#elif __has_include("PLCashierResponse.h")
   #import "PLCashierResponse.h"
#endif



@interface PLCashierResponse : NSObject
/**
 The clerk id or server id.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *clerkId;
/**
 The shift id number.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *shiftId;

@end