
#ifdef RCT_NEW_ARCH_ENABLED
#import "RNPaxPoslinkSpec.h"

@interface PaxPoslink : NSObject <NativePaxPoslinkSpec>
#else
#if __has_include(<React/RCTBridgeModule.h>)
#import <React/RCTBridgeModule.h>
#elif __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#elif __has_include(<RCTBridgeModule.h>)
#import <RCTBridgeModule.h>
#elif __has_include(<React/Base/RCTBridgeModule.h>)
#import <React/Base/RCTBridgeModule.h>
#else
#error "RCTBridgeModule.h not found"
#endif

@interface PaxPoslink : NSObject <RCTBridgeModule>
#endif

@end
