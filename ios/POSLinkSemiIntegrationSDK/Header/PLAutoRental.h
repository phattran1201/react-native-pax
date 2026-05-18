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
 Request auto rental information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLExtraChargeItem.h"
#import "PLAutoRental.h"

@interface PLAutoRental : NSObject
/**
 Car-Rental Agreement/Invoice Number issued by the rental agency.

 Attribute:ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *agreementNumber;
/**
 Total rental rate amount per day. Format $$$$$$CC.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *dailyRate;
/**
 Rental period in days.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *rentalDuration;
/**
 Car-Rental Insurance Amount. Format $$$$$$CC.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *insuranceAmount;
/**
 Maximum miles allocated for rental without charge. Total mileage for rental period.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *milesAllocated;
/**
 Amount per mile. Format $$$$$$CC

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *mileRate;
/**
 Name of the renter or name from the driver license.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *name;
/**
 The number on the driver license.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *driverLicenseNumber;
/**
 Program type for this transaction. 
 */
@property (readwrite, nonatomic, assign)enum RentalProgramType rentalProgramType;
/**
 The name or ID of the location where the vehicle was picked up.

 Attribute:ans...40 
 */
@property (readwrite, nonatomic, copy)NSString *pickupLocationName;
/**
 City where rental period started.

 Attribute:ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *pickupCity;
/**
 State where rental period started.

 Attribute:an...3 
 */
@property (readwrite, nonatomic, copy)NSString *pickupState;
/**
 Country where rental period started.

 Attribute:an...3 
 */
@property (readwrite, nonatomic, copy)NSString *pickupCountryCode;
/**
 Start of rental period timestamp. Format YYYYMMDDhhmmss.

 Attribute:n...14 
 */
@property (readwrite, nonatomic, copy)NSString *pickupDatetime;
/**
 The name or ID of the location to where the car is returned.

 Attribute:ans...40 
 */
@property (readwrite, nonatomic, copy)NSString *returnLocation;
/**
 City where the rental car is returned.

 Attribute:ans...25 
 */
@property (readwrite, nonatomic, copy)NSString *returnCity;
/**
 State where the rental car was returned.

 Attribute:an...3 
 */
@property (readwrite, nonatomic, copy)NSString *returnState;
/**
 Country where the rental car is returned.

 Attribute:an...2 
 */
@property (readwrite, nonatomic, copy)NSString *returnCountryCode;
/**
 Date and time when the rental car should be returned. Format YYYYMMDDhhmmss.

 Attribute:n...14 
 */
@property (readwrite, nonatomic, copy)NSString *returnDatetime;
/**
 Rental car total odometer reading at the time of return.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *totalMiles;
/**
 The customer tax ID.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *customerTaxId;
/**
 The customer tax ID. 
 */
@property (readwrite, nonatomic, assign)enum VehicleClassId vehicleClassId;
/**
 Extra Charge Items. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLExtraChargeItem *> *extraChargeItems;
/**
 Car-Rental special services amount. Format $$$$$$CC.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *extraChargesAmount;

@end