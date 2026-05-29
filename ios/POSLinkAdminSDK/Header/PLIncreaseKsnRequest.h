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
 Increase KSN request.
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLIncreaseKsnRequest.h"

@interface PLIncreaseKsnRequest : PLRequest
/**
 Key type. Support DesDukptKey and AesDukptKey. 
 */
@property (readwrite, nonatomic, assign)enum KeyType keyType;
/**
 Key slot number.

Monitor(S80,S300,S500,SP30,D210): 1-40(DES DUKPT and Master Session).

Prolin(D200,D220, S920,Q20,Q30,Px5,Px7): 1-99 (DES DUKPT and Master Session), 1-40(AES DUKPT).

PayDroid(A60, A80, A920, A930, Aries Series): 1-99 (DES DUKPT and Master Session), 1-40(AES DUKPT).

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *keySlot;


@end