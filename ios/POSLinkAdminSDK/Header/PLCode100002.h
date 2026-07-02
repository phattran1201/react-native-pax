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
 Error code 100002
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100002.h>)
   #import <POSLinkAdmin/PLCode100002.h>
#elif __has_include("PLCode100002.h")
   #import "PLCode100002.h"
#endif



@interface PLCode100002 : NSObject
/**
 User aborted. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted;
/**
 Aborted for card not presented. User doesn't swipe/tap/insert card on card input interface and canceled the transaction or cancel from ECR. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted01;
/**
 Aborted for card swipe/insert/tap, but terminal cannot read the PAN and AID. user didn't know what to do and canceled the transaction or cancel from ECR. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted02;
/**
 Aborted for card tapped, and the PAN and AID are read by terminal, but user canceled in the retry prompt or cancel from ECR return masked PAN and POS Entry Mode. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted03;
/**
 Aborted for card inserted, and the PAN and AID are read by terminal, but user canceled in the retry prompt or cancel from ECR return masked PAN and POS Entry Mode. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted04;
/**
 Aborted on account selection screen, press cancel button or cancel from ECR return masked PAN and POS Entry Mode. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted05;
/**
 Aborted on Budget Selection screen, press cancel button or cancel from ECR return masked PAN and POS Entry Mode. 
 */
@property (readwrite, nonatomic, copy)NSString *aborted07;

@end