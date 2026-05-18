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
 Token Administrative Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLTokenAdministrativeRequest.h"

@interface PLTokenAdministrativeRequest : PLRequest
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Token Command.

Default is Lookup. 
 */
@property (readwrite, nonatomic, assign)enum TokenCommand tokenCommand;
/**
 Token value.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *token;
/**
 Token SN. The merchant's token serial number. Valid when Token Command is Duplicate.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSn;
/**
 The token's expiration date. Format MMYY. Valid when Token Command is Update.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate;


@end