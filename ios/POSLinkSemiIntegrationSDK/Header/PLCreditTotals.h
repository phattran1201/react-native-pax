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
 CreditTotalData
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCreditTotals.h"

@interface PLCreditTotals : NSObject
/**
 SaleCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *saleCount;
/**
 Sale Amount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *saleAmount;
/**
 ForcedCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *forcedCount;
/**
 ForcedAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *forcedAmount;
/**
 ReturnCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *returnCount;
/**
 ReturnAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *returnAmount;
/**
 Authorization Count

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCount;
/**
 Authorization Amount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationAmount;
/**
 Post Authorization Count

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *postAuthorizationCount;
/**
 Post Authorization Amount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *postAuthorizationAmount;

@end