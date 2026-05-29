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
 Response Card Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCardInformation.h"

@interface PLCardInformation : NSObject
/**
 The card BIN as the leading 6 or 8 digits. If the transaction type is REPLACE, this field is the old card number.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *cardBin;
/**
 The card BIN as the leading 6 or 8 digits. Field is mandatory if the transaction type is REPLACE or MERGE.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *currentCardBin;
/**
 Card program type. 
 */
@property (readwrite, nonatomic, assign)enum CardProgramType programType;
/**
 Program specified by the host, specified for Credit. 
 */
@property (readwrite, nonatomic, assign)enum HostProgramType hostProgramType;

@end