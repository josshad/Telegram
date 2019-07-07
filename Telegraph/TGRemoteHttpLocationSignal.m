#import "TGRemoteHttpLocationSignal.h"

//#import <thirdparty/AFNetworking/AFHTTPRequestOperation.h>
#if defined(MtProtoKitDynamicFramework)
#   import <MTProtoKitDynamic/MTProtoKitDynamic.h>
#elif defined(MtProtoKitMacFramework)
#   import <MTProtoKitMac/MtProtoKitMac.h>
#else
#   import <MTProtoKit/MTProtoKit.h>
#endif

@implementation TGRemoteHttpLocationSignal

+ (SSignal *)dataForHttpLocation:(NSString *)httpLocation
{
    return [[SSignal alloc] initWithGenerator:^id<SDisposable>(SSubscriber *subscriber) {
        id<MTDisposable> disposable = [[MTHttpRequestOperation dataForHttpUrl:[[NSURL alloc] initWithString:httpLocation]] startWithNext:^(id next) {
            [subscriber putNext:next];
        } error:^(id error) {
            [subscriber putError:error];
        } completed:^{
            [subscriber putCompletion];
        }];
        return [[SBlockDisposable alloc] initWithBlock:^{
            [disposable dispose];
        }];
    }];
}

+ (SSignal *)jsonForHttpLocation:(NSString *)httpLocation
{
    return [[self dataForHttpLocation:httpLocation] mapToSignal:^SSignal *(NSData *response)
    {
        if (response == nil)
            return [SSignal fail:nil];
        
        @try
        {
            NSError *error = nil;
            id json = [NSJSONSerialization JSONObjectWithData:response options:kNilOptions error:&error];
            if (error == nil)
                return [SSignal single:json];
            else
                return [SSignal fail:error];
        }
        @catch (NSException *exception)
        {
            return [SSignal fail:nil];
        }
    }];
}

@end
