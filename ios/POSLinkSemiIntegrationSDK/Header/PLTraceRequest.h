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
 Request trace information.
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


#if __has_include(<POSLinkAdmin/PLTraceRequest.h>)
   #import <POSLinkAdmin/PLTraceRequest.h>
#elif __has_include("PLTraceRequest.h")
   #import "PLTraceRequest.h"
#endif



@interface PLTraceRequest : NSObject
/**
 The ECR reference number which is a unique code in ECR side.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *ecrReferenceNumber;
/**
 The ECR invoice number.

 Attribute : ans...50 
 */
@property (readwrite, nonatomic, copy)NSString *invoiceNumber;
/**
 The transaction record number in the terminal, required for follow up transactions after Sale/ Authorization/ Return..., i.e. Void/PostAuthorization, terminal will prompt user to enter this if this field is NULL.

0 < Index <= 5000, normal data base.

5000 < Index <= 9000, stored data base for SAF.

9000 < Index <= 9999, failed data base for SAF.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *originalReferenceNumber;
/**
 The date time, YYYYMMDDhhmmss, if this field is NULL, terminal will use local time.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 Original ECR reference number from POS system.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *originalEcrReferenceNumber;
/**
 Original Transaction Date in YYYYMMDD format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this field, the current date on the terminal will be sent.

 Attribute : n8 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionDate;
/**
 Original Transaction Time in HHMMSS format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this field, the current date on the terminal will be sent.

 Attribute : n6 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionTime;
/**
 A unique ID for each transaction. Can be used for all transaction API, Local Detail Report and DeleteTransaction.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid;

@end