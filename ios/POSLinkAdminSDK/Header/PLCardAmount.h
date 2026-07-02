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
 Request Card Amount.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardAmount.h>)
   #import <POSLinkAdmin/PLCardAmount.h>
#elif __has_include("PLCardAmount.h")
   #import "PLCardAmount.h"
#endif



@interface PLCardAmount : NSObject
/**
 Visa amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *visa;
/**
 MasterCard amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *masterCard;
/**
 AMEX amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *amex;
/**
 Diners amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *diners;
/**
 Discover amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *discover;
/**
 JCB amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *jcb;
/**
 enRoute amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *enRoute;
/**
 VisaFleet amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *visaFleet;
/**
 MasterCardFleet amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *masterCardFleet;
/**
 FleetOne amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fleetOne;
/**
 Fleetwide amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fleetwide;
/**
 Fuelman amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *fuelman;
/**
 Gascard amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *gascard;
/**
 Voyager amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voyager;
/**
 WrightExpress amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *wrightExpress;
/**
 Extended(others) amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *extended;
/**
 Interac amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *interac;
/**
 CUP amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cup;
/**
 Maestro amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *maestro;
/**
 Sinclair amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *sinclair;

@end