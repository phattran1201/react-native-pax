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
 @deprecated Since V2.01.00.
 Response Report Transaction Information.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLTransactionInformation.h>)
   #import <POSLinkAdmin/PLTransactionInformation.h>
#elif __has_include("PLTransactionInformation.h")
   #import "PLTransactionInformation.h"
#endif


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


#if __has_include(<POSLinkAdmin/PLReportTransactionInformation.h>)
   #import <POSLinkAdmin/PLReportTransactionInformation.h>
#elif __has_include("PLReportTransactionInformation.h")
   #import "PLReportTransactionInformation.h"
#endif



__attribute__((deprecated("Deprecated since V2.01.00")))
@interface PLReportTransactionInformation : PLTransactionInformation
/**
 The discount amount.

 Attribute : n...9
 @deprecated Since V2.01.00. See AmountResponse.DiscountAmount. 
 */
@property (readwrite, nonatomic, copy)NSString *discountAmount __attribute__((deprecated("Deprecated since V2.01.00. See AmountResponse.DiscountAmount")));
/**
 The signature status.

 Attribute : n1
 @deprecated Since V2.01.00. See SignatureResponse.SignatureStatus. 
 */
@property (readwrite, nonatomic, assign)enum SignatureResponseStatus signatureStatus __attribute__((deprecated("Deprecated since V2.01.00. See SignatureResponse.SignatureStatus")));
/**
 The serial number of the device.

 Attribute : ans...32
 @deprecated Since V2.01.00. See TraceResponse.Sn. 
 */
@property (readwrite, nonatomic, copy)NSString *sn __attribute__((deprecated("Deprecated since V2.01.00. See TraceResponse.Sn")));
/**
 Transaction settlement date, the format is YYYYMMDD.

 Attribute : n8
 @deprecated Since V2.01.00. See TraceResponse.SettlementDate. 
 */
@property (readwrite, nonatomic, copy)NSString *settlementDate __attribute__((deprecated("Deprecated since V2.01.00. See TraceResponse.SettlementDate")));
/**
 A unique ID for each transaction.

 Attribute : ans...64
 @deprecated Since V2.01.00. See TraceResponse.GlobalUid. 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid __attribute__((deprecated("Deprecated since V2.01.00. See TraceResponse.GlobalUid")));

@end