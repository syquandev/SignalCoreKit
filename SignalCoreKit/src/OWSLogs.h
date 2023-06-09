//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

#ifdef DEBUG
static const NSUInteger ddLogLevel = DDLogLevelAll;
#else
static const NSUInteger ddLogLevel = DDLogLevelInfo;
#endif

static inline BOOL ShouldLogVerbose()
{
    return ddLogLevel >= DDLogLevelVerbose;
}

static inline BOOL ShouldLogDebug()
{
    return ddLogLevel >= DDLogLevelDebug;
}

static inline BOOL ShouldLogInfo()
{
    return ddLogLevel >= DDLogLevelInfo;
}

static inline BOOL ShouldLogWarning()
{
    return ddLogLevel >= DDLogLevelWarning;
}

static inline BOOL ShouldLogError()
{
    return ddLogLevel >= DDLogLevelError;
}

/**
 * A minimal DDLog wrapper for swift.
 */
@interface OWSLogger : NSObject

/// When toggled, all subsequent logs at info or higher will be immediately flushed
@property (class, atomic, assign) BOOL aggressiveFlushing;

+ (void)verbose:(NSString *)logString;
+ (void)debug:(NSString *)logString;
+ (void)info:(NSString *)logString;
+ (void)warn:(NSString *)logString;
+ (void)error:(NSString *)logString;

+ (void)flush;

@end

#define OWSLogPrefix()                                                                                                 \
    ([NSString stringWithFormat:@"[%@:%d %s]: ",                                                                       \
               [[NSString stringWithUTF8String:__FILE__] lastPathComponent],                                           \
               __LINE__,                                                                                               \
               __PRETTY_FUNCTION__])

#define OWSLogDebug(_messageFormat, ...)                                                                               \
    do {                                                                                                               \
        DDLogDebug(@"💚 %@%@", OWSLogPrefix(), [NSString stringWithFormat:_messageFormat, ##__VA_ARGS__]);                \
    } while (0)


NS_ASSUME_NONNULL_END
