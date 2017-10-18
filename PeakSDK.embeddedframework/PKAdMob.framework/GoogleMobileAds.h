//
//  GoogleMobileAds.h
//  Google Mobile Ads SDK
//
//  Copyright 2014 Google Inc. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
#error The Google Mobile Ads SDK requires a deployment target of iOS 6.0 or later.
#endif

#if defined(__ARM_ARCH_7S__) && __ARM_ARCH_7S__
#error The Google Mobile Ads SDK doesn't support linking with armv7s. Remove armv7s from "ARCHS" (Architectures) in your Build Settings.
#endif

/// Project version string for GoogleMobileAds.
FOUNDATION_EXPORT const unsigned char GoogleMobileAdsVersionString[];

// Header files.
#import "GoogleMobileAdsDefines.h"

#import "GADAdNetworkExtras.h"
#import "GADAdSize.h"
#import "GADAudioVideoManagerDelegate.h"
#import "GADAudioVideoManager.h"
#import "GADBannerView.h"
#import "GADBannerViewDelegate.h"
#import "GADCorrelator.h"
#import "GADCorrelatorAdLoaderOptions.h"
#import "GADDebugOptionsViewController.h"
#import "GADExtras.h"
#import "GADInAppPurchase.h"
#import "GADInAppPurchaseDelegate.h"
#import "GADInterstitial.h"
#import "GADInterstitialDelegate.h"
#import "GADMediaView.h"
#import "GADMobileAds.h"
#import "GADNativeExpressAdView.h"
#import "GADNativeExpressAdViewDelegate.h"
#import "GADRequest.h"
#import "GADRequestError.h"
#import "GADVideoController.h"
#import "GADVideoControllerDelegate.h"
#import "GADVideoOptions.h"

#import "DFPBannerView.h"
#import "DFPBannerViewOptions.h"
#import "DFPCustomRenderedAd.h"
#import "DFPCustomRenderedBannerViewDelegate.h"
#import "DFPCustomRenderedInterstitialDelegate.h"
#import "DFPInterstitial.h"
#import "DFPRequest.h"
#import "GADAdSizeDelegate.h"
#import "GADAppEventDelegate.h"

#import "GADAdLoader.h"
#import "GADAdLoaderAdTypes.h"
#import "GADAdLoaderDelegate.h"

#import "GADAdChoicesView.h"
#import "GADNativeAd.h"
#import "GADNativeAdDelegate.h"
#import "GADNativeAdImage.h"
#import "GADNativeAdImage+Mediation.h"
#import "GADNativeAppInstallAd.h"
#import "GADNativeAppInstallAdAssetIDs.h"
#import "GADNativeContentAd.h"
#import "GADNativeContentAdAssetIDs.h"
#import "GADNativeCustomTemplateAd.h"

#import "GADMultipleAdsAdLoaderOptions.h"
#import "GADNativeAdImageAdLoaderOptions.h"
#import "GADNativeAdViewAdOptions.h"

#import "GADCustomEventBanner.h"
#import "GADCustomEventBannerDelegate.h"
#import "GADCustomEventExtras.h"
#import "GADCustomEventInterstitial.h"
#import "GADCustomEventInterstitialDelegate.h"
#import "GADCustomEventNativeAd.h"
#import "GADCustomEventNativeAdDelegate.h"
#import "GADCustomEventParameters.h"
#import "GADCustomEventRequest.h"
#import "GADMediatedNativeAd.h"
#import "GADMediatedNativeAdDelegate.h"
#import "GADMediatedNativeAdNotificationSource.h"
#import "GADMediatedNativeAppInstallAd.h"
#import "GADMediatedNativeContentAd.h"

#import "GADDynamicHeightSearchRequest.h"
#import "GADSearchBannerView.h"
#import "GADSearchRequest.h"

#import "GADAdReward.h"
#import "GADRewardBasedVideoAd.h"
#import "GADRewardBasedVideoAdDelegate.h"

#import "GADMAdNetworkAdapterProtocol.h"
#import "GADMAdNetworkConnectorProtocol.h"
#import "GADMediationAdRequest.h"
#import "GADMEnums.h"
#import "GADMRewardBasedVideoAdNetworkAdapterProtocol.h"
#import "GADMRewardBasedVideoAdNetworkConnectorProtocol.h"
