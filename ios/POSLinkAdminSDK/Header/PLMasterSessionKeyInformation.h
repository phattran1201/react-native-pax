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
 M/S Key Detail Information.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLMasterSessionKeyInformation.h>)
   #import <POSLinkAdmin/PLMasterSessionKeyInformation.h>
#elif __has_include("PLMasterSessionKeyInformation.h")
   #import "PLMasterSessionKeyInformation.h"
#endif



@interface PLMasterSessionKeyInformation : NSObject
/**
 Key slot with key injected PED.

 Attribute : n2 
 */
@property (readwrite, nonatomic, copy)NSString *keySlot;
/**
 KCV(Key Check Value) in terminal PED, corresponding to values returned in Key Slot.

 Attribute : an8 
 */
@property (readwrite, nonatomic, copy)NSString *kcv;

@end