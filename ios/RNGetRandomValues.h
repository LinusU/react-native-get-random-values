#import <React/RCTBridgeModule.h>

@interface RNGetRandomValues : NSObject <RCTBridgeModule>
-(NSString*)getRandomBase64:(NSUInteger)byteLength;
@end
