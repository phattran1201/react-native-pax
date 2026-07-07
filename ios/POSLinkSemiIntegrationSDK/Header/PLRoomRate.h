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
 Room rate.
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


#if __has_include(<POSLinkAdmin/PLRoomRate.h>)
   #import <POSLinkAdmin/PLRoomRate.h>
#elif __has_include("PLRoomRate.h")
   #import "PLRoomRate.h"
#endif



@interface PLRoomRate : NSObject
/**
 Actual or Estimated days the guest is staying in the room.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *stayDuration;
/**
 The rate of the room per night.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *roomRateAmount;
/**
 The tax amount for the room rate.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *roomRateTax;

@end