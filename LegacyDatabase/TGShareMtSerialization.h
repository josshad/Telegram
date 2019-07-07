#import <Foundation/Foundation.h>

#if defined(MtProtoKitDynamicFramework)
#   import <MTProtoKitDynamic/MTProtoKitDynamic.h>
#elif defined(MtProtoKitMacFramework)
#   import <MTProtoKitMac/MtProtoKitMac.h>
#else
#   import <MTProtoKit/MTProtoKit.h>
#endif

@interface TGShareMtSerialization : NSObject <MTSerialization>

@end
