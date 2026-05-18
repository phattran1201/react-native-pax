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
 Show Dialog Form Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLShowDialogFormResponse.h"

@interface PLShowDialogFormResponse : PLResponse
/**
 The Radio or CheckBox number of selection. Radio Selection(one only).

"1" = 1 ... "4" = 4

CheckBox Selection,

"1,2,3,4" means all four checkboxes are selected. ',' is the delimiter.

 Attribute:ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *labelSelected;


@end