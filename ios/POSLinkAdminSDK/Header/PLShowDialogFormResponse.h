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
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLShowDialogFormResponse.h>)
   #import <POSLinkAdmin/PLShowDialogFormResponse.h>
#elif __has_include("PLShowDialogFormResponse.h")
   #import "PLShowDialogFormResponse.h"
#endif



@interface PLShowDialogFormResponse : PLResponse
/**
 The Radio or CheckBox number of selection. Radio Selection(one only).

"1" = 1 ... "4" = 4

CheckBox Selection,

"1,2,3,4" means all four checkboxes are selected. ',' is the delimiter.

 Attribute : ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *labelSelected;


@end