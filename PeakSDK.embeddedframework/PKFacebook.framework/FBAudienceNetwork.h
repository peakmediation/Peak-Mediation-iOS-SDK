// Copyright 2004-present Facebook. All Rights Reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <UIKit/UIKit.h>

#import "FBAdChoicesView.h"
#import "FBAdDefines.h"
#import "FBAdSettings.h"
#import "FBAdView.h"
#import "FBInstreamAdView.h"
#import "FBInterstitialAd.h"
#import "FBMediaView.h"
#import "FBMediaViewVideoRenderer.h"
#import "FBNativeAd.h"
#import "FBNativeAdCollectionViewAdProvider.h"
#import "FBNativeAdCollectionViewCellProvider.h"
#import "FBNativeAdScrollView.h"
#import "FBNativeAdTableViewAdProvider.h"
#import "FBNativeAdTableViewCellProvider.h"
#import "FBNativeAdView.h"
#import "FBNativeAdsManager.h"
#import "FBRewardedVideoAd.h"

// NOTE: Any changes should also be made to the module.modulemap
// to ensure comptability with Swift apps using Cocoapods

#define FB_AD_SDK_VERSION @"4.26.0"
