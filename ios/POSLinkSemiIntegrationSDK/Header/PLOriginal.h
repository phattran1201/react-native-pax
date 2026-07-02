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
 Response Original Information.
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


#if __has_include(<POSLinkAdmin/PLOriginal.h>)
   #import <POSLinkAdmin/PLOriginal.h>
#elif __has_include("PLOriginal.h")
   #import "PLOriginal.h"
#endif



__attribute__((deprecated("Deprecated since V2.01.00")))
@interface PLOriginal : NSObject
/**
 Original Transaction Date in YYYYMMDD format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this field, the current date on the terminal will be sent.

 Attribute : n8
 @deprecated Since V2.01.00. See TraceRequest.OriginalTransactionDate. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionDate __attribute__((deprecated("Deprecated since V2.01.00. See TraceRequest.OriginalTransactionDate")));
/**
 Last 4 digits of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute : n4
 @deprecated Since V2.01.00. See AccountRequest.OriginalPan. 
 */
@property (readwrite, nonatomic, copy)NSString *pan __attribute__((deprecated("Deprecated since V2.01.00. See AccountRequest.OriginalPan")));
/**
 Expiry date in MMYY of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute : n4
 @deprecated Since V2.01.00. See AccountRequest.OriginalExpiryDate. 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate __attribute__((deprecated("Deprecated since V2.01.00. See AccountRequest.OriginalExpiryDate")));
/**
 Original Transaction Time in HHMMSS format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this field, the current date on the terminal will be sent.

 Attribute : n6
 @deprecated Since V2.01.00. See TraceRequest.OriginalTransactionTime. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTime __attribute__((deprecated("Deprecated since V2.01.00. See TraceRequest.OriginalTransactionTime")));
/**
 Original transaction type. Used for follow up transactions.
 @deprecated Since V2.01.00. Remove to Request class such as DoCreditRequest.OriginalTransactionType. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType __attribute__((deprecated("Deprecated since V2.01.00. Remove to Request class such as DoCreditRequest.OriginalTransactionType")));
/**
 The Original Amount, $$$$$$$CC.

 Attribute : n...9
 @deprecated Since V2.01.00. See AmountRequest.OriginalAmount. 
 */
@property (readwrite, nonatomic, copy)NSString *amount __attribute__((deprecated("Deprecated since V2.01.00. See AmountRequest.OriginalAmount")));

@end