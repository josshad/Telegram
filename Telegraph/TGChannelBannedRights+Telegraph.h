#import <Foundation/Foundation.h>

#import <LegacyComponents/LegacyComponents.h>

#import "TLMetaScheme.h"

@interface TGChannelBannedRights (TG)

- (instancetype)initWithTL:(TLChannelBannedRights *)tlRights;
- (TLChannelBannedRights *)tlRights;

@end
