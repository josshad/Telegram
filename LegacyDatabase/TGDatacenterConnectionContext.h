#import <Foundation/Foundation.h>

#if defined(MtProtoKitDynamicFramework)
#   import <MTProtoKitDynamic/MTProtoKitDynamic.h>
#elif defined(MtProtoKitMacFramework)
#   import <MTProtoKitMac/MtProtoKitMac.h>
#else
#   import <MTProtoKit/MTProtoKit.h>
#endif
#import <SSignalKit/SSignalKit.h>
#import "ApiLayer86.h"

@interface TGDatacenterConnectionContext : NSObject

@property (nonatomic, readonly) NSInteger datacenterId;
@property (nonatomic, strong, readonly) MTContext *mtContext;
@property (nonatomic, strong, readonly) MTProto *mtProto;
@property (nonatomic, strong, readonly) MTRequestMessageService *mtRequestService;

- (instancetype)initWithDatacenterId:(NSInteger)datacenterId mtContext:(MTContext *)mtContext mtProto:(MTProto *)mtProto mtRequestService:(MTRequestMessageService *)mtRequestService;

- (SSignal *)function:(Api86_FunctionContext *)functionContext;

@end

@interface TGPooledDatacenterConnectionContext : NSObject

@property (nonatomic, strong, readonly) TGDatacenterConnectionContext *context;
@property (nonatomic, copy, readonly) void (^returnContext)(TGDatacenterConnectionContext *);

- (instancetype)initWithDatacenterConnectionContext:(TGDatacenterConnectionContext *)context returnContext:(void (^)(TGDatacenterConnectionContext *))returnContext;

@end
