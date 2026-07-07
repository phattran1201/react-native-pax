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
 Transaction response information for fleet transactions, including restricted product data.
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


#if __has_include(<POSLinkAdmin/PLFleetData.h>)
   #import <POSLinkAdmin/PLFleetData.h>
#elif __has_include("PLFleetData.h")
   #import "PLFleetData.h"
#endif


#if __has_include(<POSLinkAdmin/PLFleetCardResponse.h>)
   #import <POSLinkAdmin/PLFleetCardResponse.h>
#elif __has_include("PLFleetCardResponse.h")
   #import "PLFleetCardResponse.h"
#endif



@interface PLFleetCardResponse : NSObject
/**
 Reading from the cardholder's vehicle odometer. Indicates the total number of miles the vehicle has travelled. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *odometer;
/**
 Also called "Vehicle Card Number", "Purchase Device Sequence Number", "Purchase Dev Seq", or "PDSN". The cardholder's vehicle number or purchase device sequence number. Returned when set during the request or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNumber;
/**
 The cardholder's job number. This field is separate from "Job ID". Returned when set during the request.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *jobNumber;
/**
 Also called "Driver Number". The cardholder's driver ID. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *driverId;
/**
 Also called "Fleet Employee Number". The cardholder's employee number. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNumber;
/**
 The cardholder's driver's license number. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNumber;
/**
 The cardholder's current job ID. This field is separate from the field named "Job Number". Returned when set during the request or entered after prompting.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *jobId;
/**
 The cardholder's department number. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNumber;
/**
 Generic fleet customer data. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *customerData;
/**
 Also called "Generic ID" or "Unencrypted ID Number". The cardholder's fleet ID. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *userId;
/**
 The cardholder's vehicle ID. This field is separate from the field named "Vehicle Number". Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleId;
/**
 Indicates all product types restricted from cardholder purchase. Applicable to Visa Fleet 2.0 cards only. The value will match either Purchase Restrictions (EMV tag "DF32") when applying chip-based restrictions or those received from the host when applying host-based restrictions. Returned only when present and applied to the current transaction.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *purchaseRestrictions;
/**
 Products or services requested for purchase by the cardholder, but denied by cardholder's card, the host, or both, during the current transaction. Returned only when the listed sources restrict product data included in the transaction request.

 Attribute : ans...1024 
 */
@property (readwrite, nonatomic, copy)NSArray<PLFleetData *> *restrictedProductData;
/**
 Reading from the cardholder's vehicle or trailer hubometer. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *hubometer;
/**
 The cardholder's maintenance ID. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *maintenanceId;
/**
 Also called "Contract Number". The cardholder's current contract or purchase order (PO) number. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPoNumber;
/**
 Also called "Trailer Hours". Reading from the cardholder's reefer trailer engine meter. Indicates the cumulative number of hours which the reefer engine has ran. Returned when set during the request or entered after prompting.

 Attribute : ans...7 
 */
@property (readwrite, nonatomic, copy)NSString *reeferHours;
/**
 Also called "Trailer Number" or "Trailer License Number". The cardholder's vehicle trailer ID or trailer license number. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *trailerId;
/**
 The number identifying the cardholder's current trip. Returned when set during the request or entered after prompting.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *tripNumber;
/**
 Also called "Unit Number". The cardholder's vehicle unit number. Returned when set during the request or entered after prompting.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *unitId;
/**
 Additional cardholder fleet data field reserved for forward compatibility. Applicable to Visa Fleet 2.0 cards only. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData1;
/**
 More additional cardholder fleet data field reserved for forward compatibility. Applicable to Visa Fleet 2.0 cards only. Returned when set during the request, read from the card, or entered after prompting.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData2;

@end