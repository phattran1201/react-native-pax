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
 FSA data format definition is also used to send HSA and HRA program type data.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLFsaData.h"

@interface PLFsaData : NSObject
/**
 Health care amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *healthCareAmount;
/**
 Prescription/Rx amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *rxAmount;
/**
 Vision amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *visionAmount;
/**
 Dental amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *dentalAmount;
/**
 Clinical amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *clinicalAmount;
/**
 Copay amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *copayAmount;
/**
 Transit amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *transitAmount;
/**
 Over the counter amount. Default format is $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *overTheCounterAmount;

@end