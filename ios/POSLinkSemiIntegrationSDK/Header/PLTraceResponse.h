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
 Response Trace Information.
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


#if __has_include(<POSLinkAdmin/PLTraceResponse.h>)
   #import <POSLinkAdmin/PLTraceResponse.h>
#elif __has_include("PLTraceResponse.h")
   #import "PLTraceResponse.h"
#endif



@interface PLTraceResponse : NSObject
/**
 The transaction record number in the terminal, suggest printing this on receipt.

0 < Index <= 5000, normal data base.

5000 < Index <= 9000, stored data base for SAF.

9000 < Index <= 9999, failed data base for SAF.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *referenceNumber;
/**
 The ECR reference number, echo back.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *ecrReferenceNumber;
/**
 The date time, YYYYMMDDhhmmss.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 POS system invoice/tracking number.

 Attribute : ans...50 
 */
@property (readwrite, nonatomic, copy)NSString *invoiceNumber;
/**
 The serial number of the device.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *sn;
/**
 Transaction settlement date, the format is YYYYMMDD.

 Attribute : n8 
 */
@property (readwrite, nonatomic, copy)NSString *settlementDate;
/**
 A unique ID for each transaction.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid;

@end