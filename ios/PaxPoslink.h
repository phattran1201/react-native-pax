
#ifdef RCT_NEW_ARCH_ENABLED
#import "RNPaxPoslinkSpec.h"

@interface PaxPoslink : NSObject <NativePaxPoslinkSpec>
#else
#import <React/RCTBridgeModule.h>

@interface PaxPoslink : NSObject <RCTBridgeModule>
#endif

@end
