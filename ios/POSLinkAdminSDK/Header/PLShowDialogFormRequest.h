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
 Show Dialog Form Request
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLShowDialogFormRequest.h>)
   #import <POSLinkAdmin/PLShowDialogFormRequest.h>
#elif __has_include("PLShowDialogFormRequest.h")
   #import "PLShowDialogFormRequest.h"
#endif



@interface PLShowDialogFormRequest : PLRequest
/**
 Lines of text. (use all available space)

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 Lines of text, (use all available space)

 Attribute : ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label1;
/**
 Label 1 property value. Relevant only if the ButtonType is "CheckBox". The default value is "Unchecked".

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label1Property;
/**
 Lines of text, (use all available space)

 Attribute : ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label2;
/**
 Label 2 property value. Relevant only if the ButtonType is "CheckBox". The default value is "Unchecked".

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label2Property;
/**
 Lines of text, (use all available space)

 Attribute : ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label3;
/**
 Label 3 property value. Relevant only if the ButtonType is "CheckBox". The default value is "Unchecked".

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label3Property;
/**
 Lines of text, (use all available space)

 Attribute : ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label4;
/**
 Label 4 property value. Relevant only if the ButtonType is "CheckBox". The default value is "Unchecked".

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label4Property;
/**
 Button type. Default is "RadioButton".

"CANCEL" - API return aborted.

"CLEAR" will clear the CheckBox selection.

"ACCEPT" - API return accepted.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ButtonType buttonType;
/**
 Timeout in 100ms for waiting user to confirm.Valid value should be[1, 9999], "" - no timeout, wait till user cancel or confirm.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end