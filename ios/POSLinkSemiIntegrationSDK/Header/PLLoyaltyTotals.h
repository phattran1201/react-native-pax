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
 LoyaltyTotalData
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLLoyaltyTotals.h"

@interface PLLoyaltyTotals : NSObject
/**
 RedeemCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *redeemCount;
/**
 RedeemAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *redeemAmount;
/**
 IssueCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *issueCount;
/**
 IssueAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *issueAmount;
/**
 AddCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *addCount;
/**
 AddAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *addAmount;
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
 ActivateCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *activateCount;
/**
 ActivateAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *activateAmount;
/**
 DeactivateCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *deactivateCount;
/**
 DeactivateAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *deactivateAmount;

@end