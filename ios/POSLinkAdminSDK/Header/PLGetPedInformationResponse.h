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
 Get PED information response.
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


#if __has_include(<POSLinkAdmin/PLDukptKeyInformation.h>)
   #import <POSLinkAdmin/PLDukptKeyInformation.h>
#elif __has_include("PLDukptKeyInformation.h")
   #import "PLDukptKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLDukptKeyInformation.h>)
   #import <POSLinkAdmin/PLDukptKeyInformation.h>
#elif __has_include("PLDukptKeyInformation.h")
   #import "PLDukptKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLMasterSessionKeyInformation.h>)
   #import <POSLinkAdmin/PLMasterSessionKeyInformation.h>
#elif __has_include("PLMasterSessionKeyInformation.h")
   #import "PLMasterSessionKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLMasterSessionKeyInformation.h>)
   #import <POSLinkAdmin/PLMasterSessionKeyInformation.h>
#elif __has_include("PLMasterSessionKeyInformation.h")
   #import "PLMasterSessionKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLMasterSessionKeyInformation.h>)
   #import <POSLinkAdmin/PLMasterSessionKeyInformation.h>
#elif __has_include("PLMasterSessionKeyInformation.h")
   #import "PLMasterSessionKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLMasterSessionKeyInformation.h>)
   #import <POSLinkAdmin/PLMasterSessionKeyInformation.h>
#elif __has_include("PLMasterSessionKeyInformation.h")
   #import "PLMasterSessionKeyInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetPedInformationResponse.h>)
   #import <POSLinkAdmin/PLGetPedInformationResponse.h>
#elif __has_include("PLGetPedInformationResponse.h")
   #import "PLGetPedInformationResponse.h"
#endif



@interface PLGetPedInformationResponse : PLResponse
/**
 Master available key slot count.

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *masterAvailableKeySlotCount;
/**
 Session available key slot count.

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *sessionAvailableKeySlotCount;
/**
 Dukpt available key slot count.

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *dukptAvailableKeySlotCount;
/**
 AES Dukpt available key slot count.

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *aesDukptAvailableKeySlotCount;
/**
 Terminal Master Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLMasterSessionKeyInformation *> *tmk;
/**
 Terminal PIN Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLMasterSessionKeyInformation *> *tpk;
/**
 Terminal MAC Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLMasterSessionKeyInformation *> *tak;
/**
 Terminal Des Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLMasterSessionKeyInformation *> *tdk;
/**
 DUKPT Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLDukptKeyInformation *> *dukptKey;
/**
 AES DUKPT Key information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLDukptKeyInformation *> *aesDukptKey;


@end