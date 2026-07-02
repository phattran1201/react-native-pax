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
 In this bitmap, false means off, true means on.
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


#if __has_include(<POSLinkAdmin/PLProgramBitmap.h>)
   #import <POSLinkAdmin/PLProgramBitmap.h>
#elif __has_include("PLProgramBitmap.h")
   #import "PLProgramBitmap.h"
#endif



@interface PLProgramBitmap : NSObject
/**
 Commercial Card.

false: off.

true: on.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL commercialCard;
/**
 FSA.

false: off.

true: on.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL fsa;
/**
 Fleet Card.

false: off.

true: on.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL fleetCard;
/**
 eWIC.

false: off.

true: on.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL ewic;

@end