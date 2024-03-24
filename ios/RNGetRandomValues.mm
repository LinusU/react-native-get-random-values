#import "RNGetRandomValues.h"

#if RCT_NEW_ARCH_ENABLED
#import "RNGetRandomValuesSpec.h"

@interface RNGetRandomValues () <NativeRNGetRandomValuesSpec>
@end
#endif

@implementation RNGetRandomValues

RCT_EXPORT_MODULE()

RCT_EXPORT_SYNCHRONOUS_TYPED_METHOD(NSString*, getRandomBase64:(double)byteLength) {
    NSMutableData *data = [NSMutableData dataWithLength:(NSUInteger)byteLength];
    int result = SecRandomCopyBytes(kSecRandomDefault, (NSUInteger)byteLength, data.mutableBytes);
    if (result != errSecSuccess) {
        @throw([NSException exceptionWithName:@"NO_RANDOM_BYTES" reason:@"Failed to aquire secure random bytes" userInfo:nil]);
    }
    return [data base64EncodedStringWithOptions:0];
}

#if RCT_NEW_ARCH_ENABLED
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:(const facebook::react::ObjCTurboModule::InitParams &)params {
    return std::make_shared<facebook::react::NativeRNGetRandomValuesSpecJSI>(params);
}
#endif

@end
