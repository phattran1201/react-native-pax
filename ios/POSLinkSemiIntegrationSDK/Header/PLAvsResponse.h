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
 Response AVS Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAvsResponse.h"

@interface PLAvsResponse : NSObject
/**
 Please see the host specification for the details; if host returned the value, this is mandatory.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *avsApprovalCode;
/**
 The AVS response message, if host returned AVS message, this field is mandatory.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *avsMessage;
/**
 Card holder zip code.

 Attribute:ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *zipCode;
/**
 Card holder address 1.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address1;
/**
 Card holder address 2.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *address2;

@end