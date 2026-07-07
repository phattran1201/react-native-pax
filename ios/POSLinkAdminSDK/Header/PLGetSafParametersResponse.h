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
 Get SAF Parameters Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLOfflineInformationResponse.h>)
   #import <POSLinkAdmin/PLOfflineInformationResponse.h>
#elif __has_include("PLOfflineInformationResponse.h")
   #import "PLOfflineInformationResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardAmount.h>)
   #import <POSLinkAdmin/PLCardAmount.h>
#elif __has_include("PLCardAmount.h")
   #import "PLCardAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardAmount.h>)
   #import <POSLinkAdmin/PLCardAmount.h>
#elif __has_include("PLCardAmount.h")
   #import "PLCardAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetSafParametersResponse.h>)
   #import <POSLinkAdmin/PLGetSafParametersResponse.h>
#elif __has_include("PLGetSafParametersResponse.h")
   #import "PLGetSafParametersResponse.h"
#endif



@interface PLGetSafParametersResponse : PLResponse
/**
 Store and forward mode indicator.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SafMode safMode;
/**
 Maximum number of SAF records. i.e. with max of 50, once it reaches 50 records, SAF will stop working.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *maxNumber;
/**
 Total ceiling amount. Once this amount is reached it will not accept any SAF record.

 Attribute : n...12 
 */
@property (readwrite, nonatomic, copy)NSString *totalCeilingAmount;
/**
 Ceiling amount per card type. Once this amount is reached it will not accept any SAF record.

Empty value means ceiling amount validation will not be started during SAF. 
 */
@property (readwrite, nonatomic, strong)PLCardAmount *ceilingAmountPerCardType;
/**
 HALO per card type, Once this amount per transaction is reached it will not accept any SAF record.

Empty value means HALO amount validation will not be started during SAF. 
 */
@property (readwrite, nonatomic, strong)PLCardAmount *haloPerCardType;
/**
 SAF Uploading mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SafUploadMode uploadMode;
/**
 Auto uploading checking interval in unit of 100ms.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *autoUploadIntervalTime;
/**
 Delete SAF Confirmation.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum DeleteSafConfirmation deleteSafConfirmation;
/**
 Indicates which transactions will be uploaded during the batch close.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SafUploadIndicator safUploadIndicator;
/**
 SAF Settings for Stay Offline Mode. 
 */
@property (readwrite, nonatomic, strong)PLOfflineInformationResponse *offlineInformation;


@end