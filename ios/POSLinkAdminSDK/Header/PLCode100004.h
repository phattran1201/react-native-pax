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
 Error code 100004
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLCode100004.h"

@interface PLCode100004 : NSObject
/**
 Host unsupported the transaction 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportTransaction;
/**
 Original transaction type not support 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportOriginalTransactionType;
/**
 Transaction type not support 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportTransactionType;

@end