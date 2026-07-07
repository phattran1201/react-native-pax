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
 An 8-digit bitmap. Set a digit to '1' to allow that digit's corresponding entry mode for the current transaction or set to '0' to disable that entry mode. Bit order is leftmost-first.
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


#if __has_include(<POSLinkAdmin/PLEntryModeBitmap.h>)
   #import <POSLinkAdmin/PLEntryModeBitmap.h>
#elif __has_include("PLEntryModeBitmap.h")
   #import "PLEntryModeBitmap.h"
#endif



@interface PLEntryModeBitmap : NSObject
/**
 Manual.

false: not available.

true: available.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL manual;
/**
 Swipe.

false: not available.

true: available.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL swipe;
/**
 Chip.

false: not available.

true: available.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL chip;
/**
 Contactless.

false: not available.

true: available.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL contactless;
/**
 Scan.

false: not available.

true: available.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL scan;

@end