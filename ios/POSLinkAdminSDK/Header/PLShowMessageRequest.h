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


#if __has_include(<POSLinkAdmin/PLShowMessageRequest.h>)
   #import <POSLinkAdmin/PLShowMessageRequest.h>
#elif __has_include("PLShowMessageRequest.h")
   #import "PLShowMessageRequest.h"
#endif



@interface PLShowMessageRequest : PLRequest
/**
 Title Message.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 The first display message on the terminal. The string size is dependent on the terminal screen size. If the string is longer than what can displayed, it will be trimmed.

 Attribute : ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *displayMessage1;
/**
 The second display message on terminal. Conditional for models with different screen size.

 Attribute : ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *displayMessage2;
/**
 Text pushed in top down or bottom up, default is Topdown. This value is only effective at the initial call.

 Attribute : ans1 
 */
@property (readwrite, nonatomic, assign)enum TextPushedMode textPushedMode;
/**
 Tax line to be displayed. Conditional for models with different screen size.

 Attribute : ans...49 
 */
@property (readwrite, nonatomic, copy)NSString *taxLine;
/**
 Total line to be displayed. Conditional for models with different screen size.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *totalLine;
/**
 Product image name. The image is preloaded on the terminal. Conditional for models with different screen size and terminal capability.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *imageName;
/**
 Product name or description, Conditional for models with different screen size and terminal capability.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *imageDescription;
/**
 Line item action. The default is "Add".

 Attribute : ans1 
 */
@property (readwrite, nonatomic, assign)enum LineItemAction lineItemAction;
/**
 Use to reference to a line when added. A line can be updated or deleted using this index as reference.

Multiple lines can be added/updated/deleted at once using a single command. Each index is separated with a vertical bar ("|") as separator. For example: "1|2|5" (This will affect lines with index 1, 2 and 5).

If an Item Index is specified when the first item is added, Indexed Mode will be activated. In Indexed Mode, each time an item is added, an Item Index must be provided otherwise an error will be returned. This allows lines to be updated or deleted.

If an Item Index is not specified when the first item is added, Non-Indexed Mode will be activated. In Non-Indexed Mode, Item Index will be ignored. Lines cannot be updated or deleted.

 Attribute : ans...256
 @deprecated Since V2.01.00. See ItemIndices. 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndex __attribute__((deprecated("Deprecated since V2.01.00. See ItemIndices")));
/**
 Use to reference to a line when added. A line can be updated or deleted using this index as reference.

Multiple lines can be added/updated/deleted at once using a single command.

Ex: ["1", "2", "5"]

If an Item Index is specified when the first item is added, Indexed Mode will be activated. In Indexed Mode, each time an item is added, an Item Index must be provided otherwise an error will be returned. This allows lines to be updated or deleted.

If an Item Index is not specified when the first item is added, Non-Indexed Mode will be activated. In Non-Indexed Mode, Item Index will be ignored. Lines cannot be updated or deleted.

 Attribute : var 
 */
@property (readwrite, nonatomic, copy)NSArray<NSString *> *itemIndices;


@end