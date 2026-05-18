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
 Error code 100021
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLCode100021.h"

@interface PLCode100021 : NSObject
/**
 The transaction is voided. 
 */
@property (readwrite, nonatomic, copy)NSString *alreadyVoided;
/**
 The auth transaction is completion. 
 */
@property (readwrite, nonatomic, copy)NSString *alreadyCompleted;

@end