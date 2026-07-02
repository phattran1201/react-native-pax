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
 Google Service Type Bitmap.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLGoogleServiceTypeBitmap.h>)
   #import <POSLinkAdmin/PLGoogleServiceTypeBitmap.h>
#elif __has_include("PLGoogleServiceTypeBitmap.h")
   #import "PLGoogleServiceTypeBitmap.h"
#endif



@interface PLGoogleServiceTypeBitmap : NSObject
/**
 All services. This flag must be true when specifying other flags.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL allServices;
/**
 All services except PPSE. This flag must be true when specifying other flags.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL allServicesExceptPpse;
/**
 PPSE.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL ppse;
/**
 Loyalty.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL loyalty;
/**
 Offer.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL offer;
/**
 Gift Card 1.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL giftCard1;
/**
 Private Label Card.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL privateLabelCard;
/**
 Cloud Based Wallet.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL cloudBasedWallet;
/**
 Mobile Marketing Platform.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL mobileMarketingPlatform;
/**
 Wallet Customer.

true: service type is chosen.

false: service type is not chosen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL walletCustomer;

@end