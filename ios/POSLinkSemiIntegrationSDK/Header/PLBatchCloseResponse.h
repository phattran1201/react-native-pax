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
 Batch Close Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
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


#if __has_include(<POSLinkAdmin/PLTotalTax.h>)
   #import <POSLinkAdmin/PLTotalTax.h>
#elif __has_include("PLTotalTax.h")
   #import "PLTotalTax.h"
#endif


#if __has_include(<POSLinkAdmin/PLTipCount.h>)
   #import <POSLinkAdmin/PLTipCount.h>
#elif __has_include("PLTipCount.h")
   #import "PLTipCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTipAmount.h>)
   #import <POSLinkAdmin/PLTipAmount.h>
#elif __has_include("PLTipAmount.h")
   #import "PLTipAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotalCount.h>)
   #import <POSLinkAdmin/PLTotalCount.h>
#elif __has_include("PLTotalCount.h")
   #import "PLTotalCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotalAmount.h>)
   #import <POSLinkAdmin/PLTotalAmount.h>
#elif __has_include("PLTotalAmount.h")
   #import "PLTotalAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLMerchantTotal.h>)
   #import <POSLinkAdmin/PLMerchantTotal.h>
#elif __has_include("PLMerchantTotal.h")
   #import "PLMerchantTotal.h"
#endif


#if __has_include(<POSLinkAdmin/PLTipCount.h>)
   #import <POSLinkAdmin/PLTipCount.h>
#elif __has_include("PLTipCount.h")
   #import "PLTipCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTipAmount.h>)
   #import <POSLinkAdmin/PLTipAmount.h>
#elif __has_include("PLTipAmount.h")
   #import "PLTipAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotalTax.h>)
   #import <POSLinkAdmin/PLTotalTax.h>
#elif __has_include("PLTotalTax.h")
   #import "PLTotalTax.h"
#endif


#if __has_include(<POSLinkAdmin/PLTorResponse.h>)
   #import <POSLinkAdmin/PLTorResponse.h>
#elif __has_include("PLTorResponse.h")
   #import "PLTorResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLMultiMerchant.h>)
   #import <POSLinkAdmin/PLMultiMerchant.h>
#elif __has_include("PLMultiMerchant.h")
   #import "PLMultiMerchant.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotalAmount.h>)
   #import <POSLinkAdmin/PLTotalAmount.h>
#elif __has_include("PLTotalAmount.h")
   #import "PLTotalAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLTotalCount.h>)
   #import <POSLinkAdmin/PLTotalCount.h>
#elif __has_include("PLTotalCount.h")
   #import "PLTotalCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdditionalResponseData.h>)
   #import <POSLinkAdmin/PLAdditionalResponseData.h>
#elif __has_include("PLAdditionalResponseData.h")
   #import "PLAdditionalResponseData.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostInformationResponse.h>)
   #import <POSLinkAdmin/PLHostInformationResponse.h>
#elif __has_include("PLHostInformationResponse.h")
   #import "PLHostInformationResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLBatchCloseResponse.h>)
   #import <POSLinkAdmin/PLBatchCloseResponse.h>
#elif __has_include("PLBatchCloseResponse.h")
   #import "PLBatchCloseResponse.h"
#endif



@interface PLBatchCloseResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostInformationResponse *hostInformation;
/**
 Total Count.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLTotalCount *totalCount;
/**
 Total Amount.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLTotalAmount *totalAmount;
/**
 The date time, YYYYMMDDhhmmss,	If ECR doesn't send time stamp to terminal, this field is mandatory.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 Terminal ID, If terminal id exists, this field is mandatory.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *tid;
/**
 Merchant ID, if merchant id exists, this field is mandatory.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *mid;
/**
 Multiple merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;
/**
 Transaction number for failed transaction in terminal database during the BATCH uploading process for NON SAF transaction.

Batch process is blocked and failed transaction is still in normal database.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *failedTransactionNumber;
/**
 Number of failed records during the BATCH uploading process for NON SAF transaction.

Batch process has not been blocked for failed uploading while failed transaction has been moved to failed database.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *failedCount;
/**
 Number of failed records during the SAF uploading process.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedCount;
/**
 Number of total records in SAF failed Database after the SAF uploading process.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedTotal;
/**
 TOR Information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;
/**
 Total amount for all supported EDCs excluding Credit Void and Credit Auth transactions returned in host message.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *hostSettledAmount;
/**
 Total count for all supported EDCs excluding Credit Void and Credit Auth transactions returned in host message.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *hostSettledCount;
/**
 Total return amount for all supported EDCs excluding Credit Void and Credit Auth transactions returned in the host message.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *hostSettledReturnAmount;
/**
 Return count for all supported EDCs excluding Credit Void and Credit Auth transactions returned in the host message.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *hostSettledReturnCount;
/**
 Total Taxes. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLTotalTax *> *totalTaxes;
/**
 Tip Amount.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLTipAmount *tipAmount;
/**
 Total Count.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLTipCount *tipCount;
/**
 Merchant Totals. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLMerchantTotal *> *merchantTotals;


@end