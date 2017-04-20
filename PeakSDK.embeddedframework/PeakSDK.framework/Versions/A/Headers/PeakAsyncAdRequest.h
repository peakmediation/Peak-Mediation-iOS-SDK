//
//  PeakAsyncAdRequest.h
//  PeakSDK v.0.18.0
//
//  Copyright © 2016 Peak. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^CompletionBlock)(NSString *zone);

/** PeakAsyncAdRequest it's an object for ads async fetching.*/
@interface PeakAsyncAdRequest : NSObject

/**
 * Make async call that checks ad availability and executes completionBlock if ad is available and async call is not canceled.
 * @param completionBlock block that contains ad's zone ID. All UI changes should be handled in this block, d do not change UI in other place, if you use this call.
 */
- (void)start:(CompletionBlock)completionBlock;

/**
 * Cancels start async call.
 */
- (void)cancel;

@end
