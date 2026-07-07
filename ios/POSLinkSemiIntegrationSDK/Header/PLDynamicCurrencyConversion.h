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
 DCC (Dynamic Currency Conversion) is a payment feature that allows international cardholders to choose whether to complete a transaction in their home currency instead of the local currency of the merchant. It provides transparency in exchange rates but may include additional conversion fees.
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


#if __has_include(<POSLinkAdmin/PLDynamicCurrencyConversion.h>)
   #import <POSLinkAdmin/PLDynamicCurrencyConversion.h>
#elif __has_include("PLDynamicCurrencyConversion.h")
   #import "PLDynamicCurrencyConversion.h"
#endif



@interface PLDynamicCurrencyConversion : NSObject
/**
 The rate at which one currency can be exchanged for another, determining the conversion value between different currencies. for exmaple, 0.055.

 Attribute : ans...11 
 */
@property (readwrite, nonatomic, copy)NSString *foreignExchangeRate;
/**
 A currency that is different from the local currency of the transaction location, typically used by international customers. for example, USD.

 Attribute : ans...3 
 */
@property (readwrite, nonatomic, copy)NSString *foreignCurrencyAlphaCode;
/**
 The transaction amount expressed in the foreign currency before conversion into the local currency using the FX rate. for example, 100.00.

 Attribute : ans...18 
 */
@property (readwrite, nonatomic, copy)NSString *foreignAmount;
/**
 The Markup percentage that Card scheme charges for the DCC services. It is included in the FX Rate. for example 4%.

 Attribute : ans...5 
 */
@property (readwrite, nonatomic, copy)NSString *markupPercentage;

@end