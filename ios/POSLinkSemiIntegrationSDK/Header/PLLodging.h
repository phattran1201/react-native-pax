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
 Lodging information.
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


#if __has_include(<POSLinkAdmin/PLLodgingItem.h>)
   #import <POSLinkAdmin/PLLodgingItem.h>
#elif __has_include("PLLodgingItem.h")
   #import "PLLodgingItem.h"
#endif


#if __has_include(<POSLinkAdmin/PLRoomRate.h>)
   #import <POSLinkAdmin/PLRoomRate.h>
#elif __has_include("PLRoomRate.h")
   #import "PLRoomRate.h"
#endif


#if __has_include(<POSLinkAdmin/PLLodging.h>)
   #import <POSLinkAdmin/PLLodging.h>
#elif __has_include("PLLodging.h")
   #import "PLLodging.h"
#endif



@interface PLLodging : NSObject
/**
 The room number.

 Attribute : n...25 
 */
@property (readwrite, nonatomic, copy)NSString *roomNumber;
/**
 The folio number. This is the bill/invoice number.

 Attribute : n...15 
 */
@property (readwrite, nonatomic, copy)NSString *folioNumber;
/**
 Room rates. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLRoomRate *> *roomRates;
/**
 The primary charge type for the transaction.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum PrimaryChargeType chargeType;
/**
 No-show Indicator.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum LodgingNoShowFlag noShowFlag;
/**
 The time and date of check-in. Format: YYYYMMDDhhmmss.

 Attribute : n...14 
 */
@property (readwrite, nonatomic, copy)NSString *checkInDate;
/**
 The time and date of check-in. Format: YYYYMMDDhhmmss.

 Attribute : n...14 
 */
@property (readwrite, nonatomic, copy)NSString *checkOutDate;
/**
 Special Program Code.

 Attribute : n...2 
 */
@property (readwrite, nonatomic, assign)enum LodgingSpecialProgramCode specialProgramCode;
/**
 Departure adjusted amount. Format $$$$$$CC.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *departureAdjustedAmount;
/**
 Lodging items. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLLodgingItem *> *lodgingItems;

@end