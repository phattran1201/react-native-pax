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
 Show Text Box Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLShowTextBoxResponse.h"

@interface PLShowTextBoxResponse : PLResponse
/**
 The button number of selection.

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *buttonNumber;
/**
 Signature status. 
 */
@property (readwrite, nonatomic, assign)enum SignatureStatus signStatus;
/**
 Signature data.

 Attribute:var 
 */
@property (readwrite, nonatomic, copy)NSString *signatureData;
/**
 Text input by customer. For currency input, 10000 will be returned if the customer input $100.00 on device.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *text;


@end