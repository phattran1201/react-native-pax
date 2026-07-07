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
 Response Host Trace Information.
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


#if __has_include(<POSLinkAdmin/PLHostTraceResponse.h>)
   #import <POSLinkAdmin/PLHostTraceResponse.h>
#elif __has_include("PLHostTraceResponse.h")
   #import "PLHostTraceResponse.h"
#endif



@interface PLHostTraceResponse : NSObject
/**
 ECR transaction ID, unique code in ECR side. Please check POSLink-Reference-Host Specific Remarks for details about field attributes. This field is returned by the host.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionId;
/**
 Returned by the host, the date and time the transaction occurred in YYYYMMDDHHMMSS format.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *hostTimeStamp;
/**
 Host reference number or (Transaction UID).

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 Host returned trace number, if host returns it, this field is mandatory and suggest printing this on receipt.

This usually holds the STAN or Sequence Number.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *hostTraceNumber;

@end