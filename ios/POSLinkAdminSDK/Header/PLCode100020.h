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
 Error code 100020
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLCode100020.h"

@interface PLCode100020 : NSObject
/**
 Swipe error 
 */
@property (readwrite, nonatomic, copy)NSString *swipeError;
/**
 Can't adjust tip 
 */
@property (readwrite, nonatomic, copy)NSString *cannotAdjust;

@end