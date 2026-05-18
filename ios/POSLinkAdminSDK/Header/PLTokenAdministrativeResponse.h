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
 Token Administrative Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLTokenAdministrativeResponse.h"

@interface PLTokenAdministrativeResponse : PLResponse
/**
 Token value.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *token;
/**
 Merchant's token serial number.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSn;
/**
 The Masked PAN of the card.

Examples:

XXXXXX******XXXX

XXXXXXXX****XXXX

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *maskedPan;
/**
 Card expiry data, format is MMYY.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate;


@end