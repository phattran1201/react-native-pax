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
 Service Update
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLServiceUpdate.h"

@interface PLServiceUpdate : NSObject
/**
 Service update ID.

 Attribute:ans...12 
 */
@property (readwrite, nonatomic, copy)NSString *updateId;
/**
 Provide update operations for application services. 
 */
@property (readwrite, nonatomic, assign)enum UpdateOperation updateOperation;
/**
 Details of service updates

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *updatePayload;

@end