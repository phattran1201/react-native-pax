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
 Transaction Prompt Bitmap.
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


#if __has_include(<POSLinkAdmin/PLTransactionPromptBitmap.h>)
   #import <POSLinkAdmin/PLTransactionPromptBitmap.h>
#elif __has_include("PLTransactionPromptBitmap.h")
   #import "PLTransactionPromptBitmap.h"
#endif



@interface PLTransactionPromptBitmap : NSObject
/**
 Confirm Total Amount.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL confirmTotalAmount;
/**
 Confirm Surcharge Amount.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL confirmSurchargeAmount;
/**
 Confirm Void Transaction.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL confirmVoidTransaction;
/**
 AVS - Address.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL avsAddress;
/**
 AVS - Zip.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL avsZip;
/**
 Tax.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL tax;
/**
 CVV.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL cvv;
/**
 Cashback.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL cashback;
/**
 Clerk/Server ID.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL clerkOrServerId;
/**
 Order Number / PO Number.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL orderNumberOrPoNumber;
/**
 Invoice Number.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL invoiceNumber;
/**
 Debit Account.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL debitAccount;
/**
 Gift CVD/PIN.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL giftCvdOrPin;
/**
 Gift Tender Type.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL giftTenderType;
/**
 Gift sale mode.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL giftSaleMode;
/**
 Shift ID.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL shiftId;
/**
 Table Number.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL tableNumber;
/**
 Guest Number.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL guestNumber;
/**
 Expiry Date Prompt.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL expiryDatePrompt;
/**
 MOTO Type.

false: disable.

true: enable.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)BOOL motoType;

@end