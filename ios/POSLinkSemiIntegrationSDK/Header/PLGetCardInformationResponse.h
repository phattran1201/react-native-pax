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
 Get card information response.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif


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


#if __has_include(<POSLinkAdmin/PLAccountResponse.h>)
   #import <POSLinkAdmin/PLAccountResponse.h>
#elif __has_include("PLAccountResponse.h")
   #import "PLAccountResponse.h"
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


#if __has_include(<POSLinkAdmin/PLGetCardInformationResponse.h>)
   #import <POSLinkAdmin/PLGetCardInformationResponse.h>
#elif __has_include("PLGetCardInformationResponse.h")
   #import "PLGetCardInformationResponse.h"
#endif



@interface PLGetCardInformationResponse : PLResponse
/**
 The Masked PAN of the card.

Examples:

XXXXXX******XXXX

XXXXXXXX****XXXX

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *maskedPan;
/**
 Fleet card information. 
 */
@property (readwrite, nonatomic, strong)PLFleetCardResponse *fleetCard;
/**
 Account information. 
 */
@property (readwrite, nonatomic, strong)PLAccountResponse *accountInformation;
/**
 Card unique identifier.

 Attribute : n...256 
 */
@property (readwrite, nonatomic, copy)NSString *cardUniqueIdentifier;


@end