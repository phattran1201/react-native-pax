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
 Response Card Total Count
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardTotalCount.h>)
   #import <POSLinkAdmin/PLCardTotalCount.h>
#elif __has_include("PLCardTotalCount.h")
   #import "PLCardTotalCount.h"
#endif



@interface PLCardTotalCount : NSObject
/**
 VisaCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *visaCount;
/**
 MasterCardCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *masterCardCount;
/**
 AmexCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *amexCount;
/**
 DinersCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *dinersCount;
/**
 DiscoverCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *discoverCount;
/**
 JcbCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *jcbCount;
/**
 EnRouteCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *enRouteCount;
/**
 ExtendedCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *extendedCount;
/**
 VisaFleetCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *visaFleetCount;
/**
 MasterCardFleetCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *masterCardFleetCount;
/**
 FleetOneCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *fleetOneCount;
/**
 FleetwideCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *fleetwideCount;
/**
 FuelmanCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *fuelmanCount;
/**
 GascardCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *gascardCount;
/**
 VoyagerCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *voyagerCount;
/**
 MasterCardCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *wrightExpressCount;
/**
 InteracCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *interacCount;
/**
 CUPCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cupCount;
/**
 MaestroCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *maestroCount;
/**
 SinclairCount.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *sinclairCount;

@end