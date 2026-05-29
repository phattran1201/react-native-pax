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
 Response Card Total Amount
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCardTotalAmount.h"

@interface PLCardTotalAmount : NSObject
/**
 Visa Amount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *visaAmount;
/**
 MasterCardAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *masterCardAmount;
/**
 AmexAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *amexAmount;
/**
 DinersAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *dinersAmount;
/**
 DiscoverAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *discoverAmount;
/**
 JcbAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *jcbAmount;
/**
 EnRouteAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *enRouteAmount;
/**
 ExtendedAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *extendedAmount;
/**
 VisaFleetAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *visaFleetAmount;
/**
 MasterCardFleetAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *masterCardFleetAmount;
/**
 FleetOneAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fleetOneAmount;
/**
 FleetwideAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fleetwideAmount;
/**
 FuelmanAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fuelmanAmount;
/**
 GascardAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *gascardAmount;
/**
 VoyagerAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voyagerAmount;
/**
 MasterCardAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *wrightExpressAmount;
/**
 InteracAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *interacAmount;
/**
 CUPAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cupAmount;
/**
 MaestroAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *maestroAmount;
/**
 SinclairAmount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *sinclairAmount;

@end