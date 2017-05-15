//
//  PeakSDK.h
//  PeakSDK v.0.18.0
//
//  Copyright © 2016 Peak. All rights reserved.
//

#import "PeakNativeAd.h"
#import "PeakAsyncAdRequest.h"
#import <UIKit/UIKit.h>

/**
 * Use the PeakSDKDelegate to receive callbacks on:
 * - Success or failure to initialize SDK;
 * - Success or failure to show a banner or interstitial;
 * - Interstitials closing;
 * - Rewarded interstitials granting users a reward for completing the rewarded experience.
 */
typedef NS_ENUM(NSUInteger, PKPlatformWrapperType)
{
    PKPlatformWrapperTypeNone,
    PKPlatformWrapperTypeUnity,
    PKPlatformWrapperTypeCocos,
    PKPlatformWrapperTypeAdobeAir
};

typedef NS_ENUM(NSUInteger, PKLoggingLevel)
{
    PKLoggingLevelRelease,
    PKLoggingLevelDebug,
    PKLoggingLevelAPI,
    PKLoggingLevelFull
};

typedef NS_ENUM(NSUInteger, PKTargetGender)
{
    PKTargetGenderUnspecified,
    PKTargetGenderMale,
    PKTargetGenderFemale
};

@protocol PeakSDKDelegate<NSObject>
@optional

/**
 * Notifies your app that initialization has succeeded.
 */
- (void)didCompleteInitialization;

/**
 * Notifies your app that initialization has failured.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey.
 */
- (void)didFailInitializationWithError:(NSError *)error;

/**
 * Notifies your app that a banner was successfully shown.
* @param zoneID The NSString object. It contain peakAdZoneID.
 */
- (void)didShowBannerInZone:(NSString *)zoneID;

/**
 * Notifies your app that showing of a banner was failed.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey
 */
- (void)didFailToShowBannerInZone:(NSString *)zoneID withError:(NSError *)error;

/**
 * Notifies your app that an interstitial ad will actually play.
 * This method is called when PeakSDK has taken control of the device screen and is about to begin showing an interstitial ad.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 */
- (void)didShowInterstitialInZone:(NSString *)zoneID;

/**
 * Notifies your app that showing of an interstitial ad was failed.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey
 */
- (void)didFailToShowInterstitialInZone:(NSString *)zoneID withError:(NSError *)error;

/**
 * Notifies your app that an interstitial ad completed playing and control has been returned to the app.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 */
- (void)didCloseInterstitialInZone:(NSString *)zoneID;

/**
 * Notifies your app that rewarded interstitials granting users a reward for completing the rewarded experience.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 */
- (void)didCompleteRewardExperienceInZone:(NSString *)zoneID;

/**
 * Notifies your app that receiving of a native ad was succeeded.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 */
- (void)didShowNativeInZone:(NSString *)zoneID;

/**
 * Notifies your app that receiving of a native ad was failed.
 * @param zoneID The NSString object. It contain peakAdZoneID.
 * @param error The error object. It can contain underlying error with more useful information for key NSUnderlyingErrorKey
 */
- (void)didFailToShowNativeInZone:(NSString *)zoneID withError:(NSError *)error;

@end

/** PeakSDK it's a client SDK for integration with the Peak Mediation Platform. */
@interface PeakSDK : NSObject

/*
 * Delegate object of PeakSDK
 * @param delegate (*optional*) The delegate to receive SDK events. Can be `nil` for apps that do not need these events.
 */
@property(weak, nonatomic) id<PeakSDKDelegate> delegate;

@property(assign, nonatomic) PKPlatformWrapperType platformWrapper;

/*
 * Returns the singleton PeakSDK.
 */
+ (instancetype)sharedInstance;

/**
 * Configures PeakSDK for your app; required for usage of the rest of the API.
 * PeakSDK does not begin preparing ads for display or performing reporting until after it is configured by your app.
 * @param appId The PeakSDK app ID for your app.
 */
- (void)configureWithAppId:(NSString *)appId;

/**
 * Checks that PeakSDK can show ad for zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (BOOL)canShowAdForZone:(NSString *)zone;

/**
 * Returns banner for specified zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (UIView *)showBannerForZone:(NSString *)zone;

/**
 * Shows interstitial ad specified zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (void)showInterstitialForZone:(NSString *)zone;

/**
 * Returns Native Ad for specified zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (PeakNativeAd *)showNativeAdForZone:(NSString *)zone;

/**
 * Notifies the ad networks that the Native Ad has actually been displayed on the screen and provides displaying context for this check.
 * @param zone An NSString representing the ad's zone ID.
 * @param view An UIView representing the view where native ad implemented in.
 * @param viewController An UIViewController representing the VC where native ad was shown.
 */
- (void)trackNativeAdShownForZone:(NSString *)zone inView:(UIView *)view viewController:(UIViewController *)viewController;

/**
 * Redirects the user to the website for that ad.
 * @param zone An NSString representing the ad's zone ID.
 */
- (void)handleNativeAdClickForZone:(NSString *)zone;

/**
 * Redirects the user to the website for privacy information.
 * @param zone An NSString representing the ad's zone ID.
 */
- (void)handlePrivacyIconClickForZone:(NSString *)zone;

/**
 * Returns PeakAsyncAdRequest object for specified zone.
 * @param zone An NSString representing the ad's zone ID.
 */
- (PeakAsyncAdRequest *)asyncAdRequestForZone:(NSString *)zone;

/**
 * Returns current version of SDK
 */
- (NSString *)version;

/**
 * Sets platform wrapper type
 */
- (void)setPlatformWrapperType:(PKPlatformWrapperType)platfromWrapperType;

/**
 * Sets level of logging
 */
- (void)setLogLevel:(PKLoggingLevel)logLevel;

/**
 * Sets info about user's age for more precise ad targeting
 */
- (void)setTargetingAge:(NSInteger)age;

/**
 * Sets info about user's gender for more precise ad targeting
 */
- (void)setTargetingGender:(PKTargetGender)gender;

@end
