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
 Set SAF Parameters Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLSetSafParametersRequest.h"

@interface PLSetSafParametersRequest : PLRequest
/**
 Store and forward mode indicator. 
 */
@property (readwrite, nonatomic, assign)enum SafMode safMode;
/**
 The effective start date time, YYYYMMDDhhmmss. Valid for SAF mode as 1.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *startDateTime;
/**
 The effective end date time, YYYYMMDDhhmmss. Valid for SAF mode as 1.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *endDateTime;
/**
 SAF On for next number of days from today. Valid for SAF mode as 1.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *durationInDays;
/**
 SAF max number of record - SAF only support this number of records. i.e. 50 SAF only, once it reached it will stop working.

9999 by default.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *maxNumber;
/**
 Total ceiling amount. Once this amount is reached it will not accept any SAF record.

 Attribute:n...12 
 */
@property (readwrite, nonatomic, copy)NSString *totalCeilingAmount;
/**
 Once this amount is reached it will not accept any SAF record.

Separated by Card Type with space in the card type sequence of "Visa MasterCard AMEX Diners Discover JCB enRoute VisaFleet MasterCardFleet FleetOne Fleetwide Fuelman Gascard Voyager WrightExpress Extended(other) Interac CUP Maestro Sinclair. "2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000".

1 exception that value of "2000" without any spaces means taking 2000 as unified ceiling amount for each card type.

Default as empty which means ceiling amount validation will not be started during SAF.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ceilingAmountPerCardType;
/**
 Once this amount per transaction is reached it will not accept any SAF record.

Separated by Card Type with space in the card type sequence of "Visa MasterCard AMEX Diners Discover JCB enRoute VisaFleet MasterCardFleet FleetOne Fleetwide Fuelman Gascard Voyager WrightExpress Extended(other) Interac CUP Maestro Sinclair. "2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000 2000".

1 exception that value of "2000" without any spaces means taking 2000 as unified HALO amount for each card type.

Default as empty which means HALO amount validation will not be started during SAF.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *haloPerCardType;
/**
 SAF Uploading mode. 
 */
@property (readwrite, nonatomic, assign)enum SafUploadMode uploadMode;
/**
 Auto uploading checking interval in unit of 100ms.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *autoUploadIntervalTime;
/**
 Delete SAF Confirmation. 
 */
@property (readwrite, nonatomic, assign)enum DeleteSafConfirmation deleteSafConfirmation;


@end