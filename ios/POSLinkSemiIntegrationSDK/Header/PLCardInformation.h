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
 @deprecated Since V2.01.00. See AccountResponse.
 Response Card Information.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardInformation.h>)
   #import <POSLinkAdmin/PLCardInformation.h>
#elif __has_include("PLCardInformation.h")
   #import "PLCardInformation.h"
#endif



__attribute__((deprecated("Deprecated since V2.01.00. See AccountResponse")))
@interface PLCardInformation : NSObject
/**
 The card BIN as the leading 6 or 8 digits. If the transaction type is REPLACE, this field is the old card number.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *cardBin;
/**
 The card BIN as the leading 6 or 8 digits. Field is mandatory if the transaction type is REPLACE or MERGE.

For REPLACE, this is the card which replaces the old one.

For MERGE, this is the card which the funds are merged to.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *updatedCardBin;
/**
 Card program type.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum CardProgramType programType;
/**
 Program specified by the host, specified for Credit.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum HostProgramType hostProgramType;

@end