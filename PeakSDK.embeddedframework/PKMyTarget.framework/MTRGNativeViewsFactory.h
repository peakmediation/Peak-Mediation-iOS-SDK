//
//  MTRGNativeViewsFactory.h
//  myTargetSDK 4.5.10
//
//  Created by Anton Bulankin on 17.11.14.
//  Copyright (c) 2014 Mail.ru Group. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "MTRGNativePromoBanner.h"
#import "MTRGNativeAppwallBanner.h"
#import "MTRGNewsFeedAdView.h"
#import "MTRGChatListAdView.h"
#import "MTRGContentStreamAdView.h"
#import "MTRGContentWallAdView.h"

#import "MTRGAppwallBannerAdView.h"
#import "MTRGAppwallAdView.h"

@interface MTRGNativeViewsFactory : NSObject

+ (MTRGNewsFeedAdView *)createNewsFeedViewWithBanner:(MTRGNativePromoBanner *)teaserBanner;

+ (MTRGChatListAdView *)createChatListViewWithBanner:(MTRGNativePromoBanner *)teaserBanner;

+ (MTRGContentStreamAdView *)createContentStreamViewWithBanner:(MTRGNativePromoBanner *)promoBanner;

+ (MTRGContentWallAdView *)createContentWallViewWithBanner:(MTRGNativePromoBanner *)imageBanner;

+ (MTRGAppwallBannerAdView *)createAppWallBannerViewWithBanner:(MTRGNativeAppwallBanner *)appWallBanner
                                                      delegate:(id <MTRGAppwallBannerAdViewDelegate>)delegate;

+ (MTRGAppwallBannerAdView *)createAppWallBannerViewWithDelegate:(id <MTRGAppwallBannerAdViewDelegate>)delegate;

+ (MTRGAppwallAdView *)createAppWallAdViewWithBanners:(NSArray *)banners;

@end
