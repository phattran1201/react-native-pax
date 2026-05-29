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
 GiftTotalData
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLGiftTotals.h"

@interface PLGiftTotals : NSObject
/**
 SaleCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *saleCount;
/**
 SaleAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *saleAmount;
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
 CashoutCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cashoutCount;
/**
 CashoutAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashoutAmount;
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
/**
 AdjustCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *adjustCount;
/**
 AdjustAmount

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *adjustAmount;

@end