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
 Request host trace information.
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


#if __has_include(<POSLinkAdmin/PLHostTraceRequest.h>)
   #import <POSLinkAdmin/PLHostTraceRequest.h>
#elif __has_include("PLHostTraceRequest.h")
   #import "PLHostTraceRequest.h"
#endif



@interface PLHostTraceRequest : NSObject
/**
 ECR transaction ID, unique code in ECR side. Please check POSLink-Reference-Host Specific Remarks for details about field attributes.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionId;
/**
 Original trace number which is returned in response host information.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *originalTraceNumber;
/**
 Gateway ID.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *gatewayId;
/**
 Host reference number (Transaction UID). This field is host dependent; it can be used to run Void/Return transactions.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 Original transaction settlement date, the format is YYYYMMDD.

 Attribute : n8 
 */
@property (readwrite, nonatomic, copy)NSString *originalSettlementDate;
/**
 The original batch Number.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *originalBatchNumber;

@end