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
 Apple Pay Vas
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLApplePayVas.h>)
   #import <POSLinkAdmin/PLApplePayVas.h>
#elif __has_include("PLApplePayVas.h")
   #import "PLApplePayVas.h"
#endif



@interface PLApplePayVas : NSObject
/**
 Max 5 merchant IDs connect by '#', Each merchant ID(0, 36]. Merchant IDs should not be overwritten unless the merchant ID parameter is sent in the request.

 Attribute : ans...180 
 */
@property (readwrite, nonatomic, copy)NSString *merchantId;
/**
 Url Mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum UrlMode urlMode;
/**
 Merchant URL.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *url;
/**
 Enter the key file names in the same order so that it corresponds with the Merchant IDs being set in VAS Data. The total number of key files entered must match the total number of Merchant IDs entered. Example of Valid Key File Name: VAS_KEY3.PEM

Total length up to 64 characters.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSArray<NSString *> *keyFileMapping;

@end