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
 DUKPT Key Information.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLDukptKeyInformation.h"

@interface PLDukptKeyInformation : NSObject
/**
 Key slot with key injected PED.

 Attribute:n2 
 */
@property (readwrite, nonatomic, copy)NSString *keySlot;
/**
 KSN(Key Serial Number) in terminal PED. corresponding to values returned in Key Slot.

 Attribute:an...24 
 */
@property (readwrite, nonatomic, copy)NSString *ksn;
/**
 KCV(Key Check Value) in terminal PED, corresponding to values returned in Key Slot.

 Attribute:an...32 
 */
@property (readwrite, nonatomic, copy)NSString *kcv;

@end