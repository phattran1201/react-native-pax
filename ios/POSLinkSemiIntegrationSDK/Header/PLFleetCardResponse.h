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
 Response Fleet Card Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLFleetCardResponse.h"

@interface PLFleetCardResponse : NSObject
/**
 Identifies the vehicle's odometer reading keyed in by the customer or clerk, numeric only.

 Attribute:n...16 
 */
@property (readwrite, nonatomic, copy)NSString *odometer;
/**
 Identifies the vehicle number.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNumber;
/**
 Identifies the job number.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *jobNumber;
/**
 Identifies the unencrypted driver number or identification number. Numeric only.

 Attribute:n...20 
 */
@property (readwrite, nonatomic, copy)NSString *driverId;
/**
 Identifies the fleet employee number.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNumber;
/**
 Identifies the license number of the fleet card user.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNumber;
/**
 Identifies the job id.

 Attribute:n...24 
 */
@property (readwrite, nonatomic, copy)NSString *jobId;
/**
 Identifies the department number.

 Attribute:ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNumber;
/**
 Identifies the customer data.

 Attribute:ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *customerData;
/**
 Identifies the user id.

 Attribute:ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *userId;
/**
 Identifies the vehicle id number, numeric only.

 Attribute:n...16 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleId;

@end