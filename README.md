PeakSDK
=======

## Discussion

#### Peak Mediation’s is 100% aligned with that of the publisher, which is different than every other mediation solution.

Our mediation technology is built to truly make each ad network and demand source compete, dynamically, for each ad call, with out ANY WORK by you.

Other companies don’t build their technology to optimize for mediation. They build their technology to have their exchange called first, and then give basic tools to bring in other networks. They only make money if their exchange gets a lot of traffic.

We don’t own our own exchange or source our own demand dollars. That allows us to work with unlimited demand partners, get the highest CPM from them, and then pay you in one check. We only make money by bringing in the highest CPM for you.

With Peak Mediation’s SDK bringing in every important demand source available, there is no need to take multiple SDKs just to get access to multiple ad networks.

If you are only going to test out one SDK this month, Peak Mediation’s all encompassing SDK is super simple to integrate. We collect from all the networks and pay you on single Check. What could be easier!

## Integration Instructions

### Install CocoaPods

[CocoaPods: The Objective-C Library Manager](http://www.cocoapods.org) allows you to manage the library dependencies of your iOS Xcode project. You can install the CocoaPods tool on OS X by running the following command from the terminal. Detailed information is available in the [Getting Started guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

	$ sudo gem install cocoapods

### Install Git Large File Storage

[Git LFS](https://git-lfs.github.com) replaces large files such as libraries and SDK with text pointers inside Git, while storing the file contents on a remote server. It allows CocoaPods to download large dependencies without problems. You can install the Git LFS tool on OS X by running the following command from the terminal. Detailed information is available in the [Getting Started guide](https://git-lfs.github.com).

    $ sudo git lfs install

### Add a PeakSDK to your iOS app

CocoaPods is used to install and manage dependencies in existing Xcode projects.

1. Create an Xcode project, and save it to your local machine.
2. Create a file named Podfile in your project directory. This file defines your project's dependencies, and is commonly referred to as a Podspec.
3. Open Podfile, and add your dependencies. A simple Podspec is shown here:

        platform :ios, '8.0'

        target 'YOUR_TARGET_NAME' do
            pod 'PeakSDK', :git => 'https://github.com/peakmediation/Peak-Mediation-iOS-SDK.git'
        end

4. Save the file.
5. Open a terminal and cd to the directory containing the Podfile.

		$ cd <path-to-project>/project/

6. Run the pod install command. This will install the SDKs specified in the Podspec, along with any dependencies they may have.

		$ pod install

7. Open your app's .xcworkspace file to launch Xcode. Use this file for all development on your app.

### Disabling ATS

App Transport Security (ATS) requires apps to make secure network connections via SSL and enforces HTTPS connections through its requirements on the SSL version, encryption cipher, and key length. At this time, however, we require that publishers disable ATS for PeakSDK. This can be done two ways; please see below.

**Option 1**

The easiest way to turn off ATS for PeakSDK is to disable it for the entire application by adding the following entry to the app's plist:

    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSAllowsArbitraryLoads</key>
        <true/>
    </dict>

**Option 2**

Disabling ATS for PeakSDK does not require that it be turned off for the entire application, however. In an effort to be aligned with Apple's recommendations around ATS, publishers may want to ensure their apps are as ATS-compliant as they can be. If you are one of those publishers, then Option 2 is what you want. To disable ATS for PeakSDK but keep it enabled for other domains, simply add the XML from Option 1 to your app's plist (which disables ATS for the entire application), and then add an exception for each domain known to be ATS-compliant. Please refer to the example below.

    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSAllowsArbitraryLoads</key>
        <true/>
        <key>NSExceptionDomains</key>
        <dict>
            <key>example.com</key>
            <dict>
                <key>NSIncludesSubdomains</key>
                <true/>
            </dict>
        </dict>
    </dict>

### Using canOpenURL:

Apple has also restricted usage of the `canOpenURL:` API, which PeakSDK uses to make decisions about whether or not we can land users in certain apps from our Dynamic End Cards (DECs). For example, one of our ad units could be for a new movie, and the associated DEC may present functionality to the user that allows them to send a tweet about it using the Twitter app. This kind of functionality is still possible in iOS 9, but publishers must enable it for the applications PeakSDK links to by authorizing each app’s URL scheme in their plist. Note that if the schemes are not added, users will be taken to the app’s website instead, which may result in an undesirable user experience - having to login to the site, for example. In order to enable deep-linking for the apps the PeakSDK uses, please add the following entry to your apps plist:

	<key>LSApplicationQueriesSchemes</key>
    <array>
        <string>fb</string>
        <string>instagram</string>
        <string>tumblr</string>
        <string>twitter</string>
    </array>

### Disabling Bitcode

Bitcode is an intermediate representation of a compiled program. Apps you upload to iTunes Connect that contain bitcode will be compiled and linked on the App Store. Including bitcode will allow Apple to re-optimize your app binary in the future without the need to submit a new version of your app to the store. For now PeakSDK requires disable bitcode option. Set 'Enable Bitcode' option to 'NO' in 'Build Settings'.

### Enable Geolocation

Please add the NSLocationWhenInUseUsageDescription key to your Info.plist:

    <key>NSLocationWhenInUseUsageDescription</key>
    <string>Ads targeting</string>

### Enjoy Peak Medation platform

1. Sign Up and Login to the [Peak Mediation platform](http://dashboard.peakmediation.com).
2. Add Application from the Sidebar Menu.
3. Select Name link in the Applications list.
4. Copy 'Application ID' from the 'Application details' section.
5. Copy IDs of 'Ad Zones' from the 'Ad Zones' table. Add your own zones if it needed.

### Using PeakSDK

1. Import PeakSDK in your source files:

        #import <PeakSDK/PeakSDK.h>

2. Initialize SDK with your AppID:

        [[PeakSDK sharedInstance] configureWithAppId:@"YOUR_APP_ID"];

    It’s usually enough to call initialization once per app launch. PeakSDKDelegate methods allows to control initialization state:

        - (void)didCompleteInitialization;
        - (void)didFailInitializationWithError:(NSError *)error;
        
    Multiple initializations calls are not the best practice but latest Peak SDK version can handle this correctly.

3. Check availability of ad in particular zone:

        BOOL canShow = [[PeakSDK sharedInstance] canShowAdForZone:@"YOUR_ZONE_ID"];

4. Show insterstitial ad (for example by button click):

        [[PeakSDK sharedInstance] showInterstitialForZone:@"YOUR_ZONE_ID"];

5. Get banner view. You can place it in your app everywhere you want:

        UIView *banner = [[PeakSDK sharedInstance] showBannerForZone:@"YOUR_ZONE_ID"];

6. Get native ad. Native Ads will allow developers to show ads in custom formats in their applications:

        PeakNativeAd *native = [[PeakSDK sharedInstance] showNativeAdForZone:@"YOUR_ZONE_ID"];
    
    Unlike Banner and Interstitial ads, the impressions and clicks are not automatically handled, and need to be wrapped when events do occur. Call the next method to track that native ad for current zone was shown:

        [[PeakSDK sharedInstance] trackNativeAdShownForZone:@"YOUR_ZONE_ID" inView:adView viewController:viewController];
    
    Use the next method to handle click on the "Call to Action" button. Call of this method will redirect the user to the website for privacy information:

        [[PeakSDK sharedInstance] handleNativeAdClickForZone:@"YOUR_ZONE_ID"];
        
    Use the next method to handle click on the "Privacy Icon" button. Call of this method will redirect the user to the website for that ad:

        [[PeakSDK sharedInstance] handlePrivacyIconClickForZone:@"YOUR_ZONE_ID"];
        
    Make sure your ads are clearly distinguished from the rest of your app’s content. You must include clearly visible text that reads “Promoted,” “Sponsored,” “Ad” or a localized version thereof.

7. Handle SDK events using delegate pattern:

        [[PeakSDK sharedInstance] setDelegate:self];

    PeakSDKDelegate provides protocol to implement proper response on PeakSDK events such as successful and unsuccessful ads presentation, completing reward experience or closing interstitials.
        
8. Make async call that checks ad availability and executes completionBlock if ad is available and async call is not canceled.
   All UI changes should be handled in completionBlock, do not change UI in other place, if you use this call.

        PeakAsyncAdRequest *asyncRequest = [[PeakSDK sharedInstance] asyncAdRequestForZone:zone];
        [self setAsyncRequest:asyncRequest];
        [asyncRequest start:completionBlock];
        
    If you want to cancel async call use following method:
    
        [[self asyncRequest] cancel];

    Don’t forget to cancel async request if you don’t need one anymore. It prevent unexpected ads presentations and other unhandled behaviour. 

9. Get more pesonalized ads with higher revenue. Just provide consumer's targeting info:

        [[PeakSDK sharedInstance] setTargetingAge:[user age]];
        [[PeakSDK sharedInstance] setTargetingGender:[user gender]];

    You must set this info before calling -configureWithAppId: method.
