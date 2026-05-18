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
 eWIC Balance information group.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLEwicBalance.h"

@interface PLEwicBalance : NSObject
/**
 Product code.

 Attribute:n2 
 */
@property (readwrite, nonatomic, copy)NSString *productCode;
/**
 Sub-product code.

 Attribute:n3 
 */
@property (readwrite, nonatomic, copy)NSString *subCode;
/**
 Balance.

 Attribute:n...5 
 */
@property (readwrite, nonatomic, copy)NSString *balance;

@end