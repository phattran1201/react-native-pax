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
 Delete SAF File Response.
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTorResponse.h"
#import "PLDeleteSafFileResponse.h"

@interface PLDeleteSafFileResponse : PLResponse
/**
 Total number of records deleted.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *safDeletedCount;
/**
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;


@end