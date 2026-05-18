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
 Google Smart Tap
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLGoogleServiceTypeBitmap.h"
#import "PLGoogleSmartTapCapBitmap.h"
#import "PLGoogleSmartTap.h"

@interface PLGoogleSmartTap : NSObject
/**
 Bitmaps for the various capabilities that the ECR supports. 
 */
@property (readwrite, nonatomic, strong)PLGoogleSmartTapCapBitmap *googleSmartTapCap;
/**
 Predefined number specific to the merchant.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *collectId;
/**
 Merchant address code.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *storeLocalId;
/**
 Merchant terminal code.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *terminalId;
/**
 Merchant name.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *merchantName;
/**
 Digit merchant code referring to the category of the merchant as defined by the networks.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *merchantCategory;
/**
 Service Type. 
 */
@property (readwrite, nonatomic, strong)PLGoogleServiceTypeBitmap *serviceType;
/**
 Security. 
 */
@property (readwrite, nonatomic, assign)enum Security security;
/**
 End Tap

Default is NormalFlow. 
 */
@property (readwrite, nonatomic, assign)enum EndTap endTap;
/**
 Ose To Ppse.

Default is NormalFlow. 
 */
@property (readwrite, nonatomic, assign)enum OseToPpse oseToPpse;

@end