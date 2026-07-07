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
 Request Offline Information.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLOfflineInformationRequest.h>)
   #import <POSLinkAdmin/PLOfflineInformationRequest.h>
#elif __has_include("PLOfflineInformationRequest.h")
   #import "PLOfflineInformationRequest.h"
#endif



@interface PLOfflineInformationRequest : NSObject
/**
 The effective start date time, YYYYMMDDhhmmss. Valid for when safMode is "StayOffline".

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *startOfflineDateTime;
/**
 The effective end date time, YYYYMMDDhhmmss. Valid for when safMode is "StayOffline".

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *endOfflineDateTime;
/**
 SAF On for next number of days from today. Valid for when safMode is "StayOffline".

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *durationOfflineInDays;

@end