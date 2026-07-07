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
 Printer Request
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLPrinterRequest.h>)
   #import <POSLinkAdmin/PLPrinterRequest.h>
#elif __has_include("PLPrinterRequest.h")
   #import "PLPrinterRequest.h"
#endif



@interface PLPrinterRequest : PLRequest
/**
 The number of receipt copies to print. The value must be between 1 and 9. The default value is 1.

 Attribute : n1 
 */
@property (readwrite, nonatomic, copy)NSString *printCopy;
/**
 Variable length up to 4000. Refer to the section of PrintData for how to format the print data. The ASCII characters ranging from 0x40 to 0x7F can be printed.

 Attribute : ans...4000 
 */
@property (readwrite, nonatomic, copy)NSString *printData;


@end