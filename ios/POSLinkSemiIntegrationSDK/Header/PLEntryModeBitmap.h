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
 In this bitmap, 1 means available, 0 means not available.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLEntryModeBitmap.h"

@interface PLEntryModeBitmap : NSObject
/**
 Manual.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL manual;
/**
 Swipe.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL swipe;
/**
 Chip.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL chip;
/**
 Contactless.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL contactless;
/**
 Scan.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL scan;
/**
 Check Reader.

false: not available.

true: available. 
 */
@property (readwrite, nonatomic, assign)BOOL checkReader;

@end