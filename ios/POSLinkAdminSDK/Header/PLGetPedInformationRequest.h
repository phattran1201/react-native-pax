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
 Get PED information request.
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


#if __has_include(<POSLinkAdmin/PLGetPedInformationRequest.h>)
   #import <POSLinkAdmin/PLGetPedInformationRequest.h>
#elif __has_include("PLGetPedInformationRequest.h")
   #import "PLGetPedInformationRequest.h"
#endif



@interface PLGetPedInformationRequest : PLRequest
/**
 Key type.

Empty value means all key information.

If you want to specify Key Slot, you need to specify key type first.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum KeyType keyType;
/**
 Slot, Slots or Range of Slot; Use Comma (,) to separate slot numbers and Dash ( - ) to indicate range.

Empty value means all slot.

 Attribute : var 
 */
@property (readwrite, nonatomic, copy)NSString *keySlot;


@end