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
 Do Signature Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLDoSignatureRequest.h"

@interface PLDoSignatureRequest : PLRequest
/**
 Upload flag. 
 */
@property (readwrite, nonatomic, assign)enum UploadFlag uploadFlag;
/**
 Which transaction need do signature.This parameter may be used that upload flag is need upload to host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 This parameter may be used that upload flag is need upload to host. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 This is timeout for doing signature. The timeout unit is 100ms. The valid value should be from 150 to 9999. If value is null, it means no timeout and waiting for user cancelation or confirmation.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end