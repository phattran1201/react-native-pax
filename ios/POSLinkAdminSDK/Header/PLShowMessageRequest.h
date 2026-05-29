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
 Show Message Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLShowMessageRequest.h"

@interface PLShowMessageRequest : PLRequest
/**
 The display message on terminal, the string size is terminal screen size dependent.If the string is longer than what it can displayed. It will be trimmed.

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *displayMessage1;
/**
 Title Message.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 The second display message on terminal. Conditional for models with different screen size.

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *displayMessage2;
/**
 Text pushed in top down or bottom up, default is Topdown. This value is only effective at the initial call. 
 */
@property (readwrite, nonatomic, assign)enum TextPushedMode textPushedMode;
/**
 Tax line to be displayed. Conditional for models with different screen size.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *taxLine;
/**
 Total line to be displayed. Conditional for models with different screen size.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *totalLine;
/**
 Product image name. The image is preloaded on the terminal. Conditional for models with different screen size and terminal capability.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *imageName;
/**
 Product name or description, Conditional for models with different screen size and terminal capability.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *imageDescription;
/**
 Line item action. 
 */
@property (readwrite, nonatomic, assign)enum LineItemAction lineItemAction;
/**
 Use to reference to a line when added. A line can be updated or deleted using this index as reference.

 Attribute:ans...256 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndex;


@end