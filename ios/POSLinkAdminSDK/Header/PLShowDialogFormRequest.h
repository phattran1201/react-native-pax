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
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLShowDialogFormRequest.h"

@interface PLShowDialogFormRequest : PLRequest
/**
 Lines of text. (use all available space)

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 Lines of text, (use all available space)

 Attribute:ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label1;
/**
 Label 1 property value. Relevant only if the ButtonType is "CheckBox". 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label1Property;
/**
 Lines of text, (use all available space)

 Attribute:ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label2;
/**
 Label 2 property value. Relevant only if the ButtonType is "CheckBox". 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label2Property;
/**
 Lines of text, (use all available space)

 Attribute:ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label3;
/**
 Label 3 property value. Relevant only if the ButtonType is "CheckBox". 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label3Property;
/**
 Lines of text, (use all available space)

 Attribute:ans...90 
 */
@property (readwrite, nonatomic, copy)NSString *label4;
/**
 Label 4 property value. Relevant only if the ButtonType is "CheckBox". 
 */
@property (readwrite, nonatomic, assign)enum LabelProperty label4Property;
/**
 Button type. Default is "RadioButton".

"CANCEL" - API return abort.

"CLEAR" will clear the CheckBox selection

"ACCEPT" - API return accept 
 */
@property (readwrite, nonatomic, assign)enum ButtonType buttonType;
/**
 Timeout in 100ms for waiting user to confirm.Valid value should be[1, 9999]"" - no timeout, wait till user cancel or confirm.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end