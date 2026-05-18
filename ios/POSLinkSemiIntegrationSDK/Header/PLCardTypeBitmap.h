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
 In this bitmap, 1 for each position means the specified card type is accepted, 0 indicates that the card type is not accepted.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCardTypeBitmap.h"

@interface PLCardTypeBitmap : NSObject
/**
 Visa.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL visa;
/**
 Master Card.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL masterCard;
/**
 AMEX.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL amex;
/**
 Discover.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL discover;
/**
 Diner Club.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL dinerClub;
/**
 enRoute.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL enRoute;
/**
 JCB.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL jcb;
/**
 Revolution Card.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL revolutionCard;
/**
 Visa Fleet.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL visaFleet;
/**
 Master Card Fleet.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL masterCardFleet;
/**
 Fleet One.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL fleetOne;
/**
 Fleetwide.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL fleetwide;
/**
 Fuelman.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL fuelman;
/**
 Gascard.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL gascard;
/**
 Voyager.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL voyager;
/**
 Wright Express.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL wrightExpress;
/**
 Interac.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL interac;
/**
 Cup.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL cup;
/**
 Maestro.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL maestro;
/**
 Sinclair.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL sinclair;
/**
 Gift/Loyalty (Store Value).

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL giftOrLoyalty;
/**
 OTHER. If the card not in the range, turn to OTHER as the card type.

false: not accepted.

true: accepted. 
 */
@property (readwrite, nonatomic, assign)BOOL other;

@end