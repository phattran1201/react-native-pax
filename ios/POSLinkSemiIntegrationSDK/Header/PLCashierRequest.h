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
 Request cashier information.
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


#if __has_include(<POSLinkAdmin/PLCashierRequest.h>)
   #import <POSLinkAdmin/PLCashierRequest.h>
#elif __has_include("PLCashierRequest.h")
   #import "PLCashierRequest.h"
#endif



@interface PLCashierRequest : NSObject
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
/**
 Can be used as station number/id, LaneID, RegisterID. Use for transaction APIs.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *stationId;

@end