//
//  InlineVideoAd.h
//  Test
//
//  Created by Itamar Nabriski on 6/4/15.
//  Copyright (c) 2015 Itamar Nabriski. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "MobFoxCustomEvent.h"
#import "MFWKWebViewJavascriptBridge.h"
#import "MFLocationServicesManager.h"
#import "MFExceptionHandler.h"

@class MobFoxAd;

@protocol MobFoxAdDelegate <NSObject>

@optional

- (void)MobFoxAdDidLoad:(MobFoxAd *)banner;

- (void)MobFoxAdDidFailToReceiveAdWithError:(NSError *)error;

- (void)MobFoxAdClosed;

- (void)MobFoxAdClicked;

- (void)MobFoxAdFinished;

- (void)MobFoxDelegateCustomEvents:(NSArray*)events withAdDict:(NSDictionary *)adDict;

@end


@interface MobFoxAd : UIView <WKNavigationDelegate, MobFoxCustomEventDelegate, UIGestureRecognizerDelegate>


    @property (nonatomic, weak) id <MobFoxAdDelegate> delegate;
    @property (nonatomic, strong) MFWKWebViewJavascriptBridge *bridge;
    @property (nonatomic, strong) MFLocationServicesManager *locationServicesManager;

    @property (nonatomic, copy) NSString* position;
    @property (nonatomic, copy) NSString* longitude;
    @property (nonatomic, copy) NSString* latitude;
    @property (nonatomic, copy) NSString* accuracy;
    @property (nonatomic, copy) NSString* demo_gender; //"m/f"
    @property (nonatomic, copy) NSString* demo_age;
    @property (nonatomic, copy) NSString* s_subid;
    @property (nonatomic, copy) NSString* sub_name;
    @property (nonatomic, copy) NSString* sub_domain;
    @property (nonatomic, copy) NSString* sub_storeurl;
    @property (nonatomic, copy) NSString* r_floor;
    @property (nonatomic, copy) NSString* type; //"waterfall" / "video"
    @property (nonatomic, copy) NSString* adFormat;
    @property (nonatomic, copy) NSNumber* adspace_width;
    @property (nonatomic, copy) NSNumber* adspace_height;
    @property (nonatomic, copy) NSNumber* v_dur_min;
    @property (nonatomic, copy) NSNumber* v_dur_max;
    @property (nonatomic, strong) NSString* invh;
    @property (nonatomic, strong, setter = setRefresh:) NSNumber* refresh;

    @property (nonatomic, assign) BOOL skip;
    @property (nonatomic, assign) BOOL no_markup;
   
    @property (nonatomic, assign) BOOL debug;
    @property (nonatomic, assign) BOOL delegateCustomEvents;
    @property (nonatomic, assign) BOOL autoplay;


//- (NSString *)getIPAddress;
- (id) init:(NSString*)invh;
- (id) init:(NSString*)invh withFrame:(CGRect)aRect;

- (void) loadAd;

//- (void)webViewDidStartLoad:(UIWebView *)webView;
//- (void)webViewDidFinishLoad:(UIWebView *)webView;
//- (void)webViewdidFailLoadWithError:(NSError *)error;

/*
- (void)MFCustomEventAd:(MobFoxCustomEvent *)event didLoad:(UIView *)ad;
- (void)MFCustomEventAdDidFailToReceiveAdWithError:(NSError *)error;
- (void)MFCustomEventAdClosed;
- (void)MFCustomEventMobFoxAdClicked;
- (void)MFCustomEventMobFoxAdFinished;
*/

- (void)play;
- (void)pause;
- (void)resume;
+ (void)locationServicesDisabled:(BOOL)disabled;
- (void)renderAd:(NSDictionary *)adDict;
- (BOOL)isViewVisible;

- (void)_changeWidth:(float) newWidth;
- (void)_setFrame:(CGRect)aRect;
- (void)_setSize:(CGSize)size withContainer:(CGSize)container;



@end


