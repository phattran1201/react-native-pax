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
 Transaction request information for fleet transactions. This subgroup may also be used to transmit product data to the host during non-fleet transactions, such as fuel purchases.
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


#if __has_include(<POSLinkAdmin/PLFleetCardRequest.h>)
   #import <POSLinkAdmin/PLFleetCardRequest.h>
#elif __has_include("PLFleetCardRequest.h")
   #import "PLFleetCardRequest.h"
#endif



@interface PLFleetCardRequest : NSObject
/**
 Reading from the cardholder's vehicle odometer. Indicates the total number of miles the vehicle has travelled. Required by most fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *odometer;
/**
 Also called "Vehicle Card Number", "Purchase Device Sequence Number", "Purchase Dev Seq", or "PDSN". The cardholder's vehicle number or purchase device sequence number. Required by certain fleet cards. Value is printed onto applicable cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNumber;
/**
 The cardholder's job number. This field is separate from "Job ID" and is not currently required for any supported fleet card. However, BroadPOS may still send this data to supporting hosts.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *jobNumber;
/**
 Also called "Driver Number". The cardholder's driver ID. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *driverId;
/**
 Also called "Fleet Employee Number". The cardholder's employee number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNumber;
/**
 The cardholder's driver's license number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNumber;
/**
 The cardholder's current job ID. This field is separate from the field named "Job Number". Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *jobId;
/**
 The cardholder's department number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNumber;
/**
 Generic fleet customer data. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *customerData;
/**
 Also called "Generic ID" or "Unencrypted ID Number". The cardholder's fleet ID. Required by certain fleet cards. Typically, hosts accept both Driver ID and Vehicle ID values for this field. If this field is required and not set, the application will prompt for it.

 Attribute : ans...24 
 */
@property (readwrite, nonatomic, copy)NSString *userId;
/**
 The cardholder's vehicle ID. This field is separate from the field named "Vehicle Number". Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : n...16 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleId;
/**
 Determines the prompts shown during manually entered Wright Express (WEX) card fleet transactions. Value is printed onto applicable cards. If this field is required and not set, the application will prompt for it. 

See SemiIntegrationReference - WEX Fleet Prompt Codes and for valid values.

 Attribute : n2 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPromptCode;
/**
 Products or services which the cardholder requested for purchase, such as fuel. Required during all petroleum-industry transactions, including during non-fleet transactions. Also required during some fleet transactions, depending on the host and fleet card used. 

During fleet transactions, some products may restrict the purchase, depending on the provided fleet card's allowable purchases. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLFleetData *> *fleetProductData;
/**
 The vehicle usage code in fleet transactions. It's essential identifier used to categorize and track the purpose and type of vehicle activities within a fleet management system.

Valid Only when do Credit transaction. 
 */
@property (readwrite, nonatomic, assign)enum VehicleUsageCode vehicleUsageCode;
/**
 Reading from the cardholder's vehicle or trailer hubometer. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *hubometer;
/**
 The cardholder's maintenance ID. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *maintenanceId;
/**
 Also called "Contract Number". The cardholder's current contract or purchase order (PO) number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPoNumber;
/**
 Also called "Trailer Hours". Reading from the cardholder's reefer trailer engine meter. Indicates the total number of hours which the reefer engine has ran. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...7 
 */
@property (readwrite, nonatomic, copy)NSString *reeferHours;
/**
 Determines the prompts shown and purchase restrictions applied during manually entered Voyager fleet transactions. Value is printed onto applicable cards. If this field is required and not set, the application will prompt for it.

 Attribute : n2 
 */
@property (readwrite, nonatomic, copy)NSString *restrictionCode;
/**
 Also called "Trailer Number" or "Trailer License Number". The cardholder's vehicle trailer ID or trailer license number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *trailerId;
/**
 The number identifying the cardholder's current trip. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *tripNumber;
/**
 Also called "Unit Number". The cardholder's vehicle unit number. Required by certain fleet cards. If this field is required and not set, the application will prompt for it.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *unitId;
/**
 Additional cardholder fleet data field reserved for forward compatibility. Applicable to Visa Fleet 2.0 cards only. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData1;
/**
 More additional cardholder fleet data field reserved for forward compatibility. Applicable to Visa Fleet 2.0 cards only. If this field is required and not set, the application will prompt for it.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData2;

@end