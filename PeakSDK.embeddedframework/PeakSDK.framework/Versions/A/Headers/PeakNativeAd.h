//
//  PeakNativeAd.h
//  PeakSDK v.0.18.0
//
//  Copyright © 2016 Peak. All rights reserved.
//

#import <Foundation/Foundation.h>

/** PeakNativeAd it's a Native Ad model. Native Ads return strings and images to app developers, who can then customize the formatting in their app. Unlike Banner and Interstitial ads, the impressions and clicks are not automatically handled, and need to be wrapped when events do occur.*/
@interface PeakNativeAd : NSObject

/*
 * @param title (*optional*) The title for the ad.
 */
@property(copy, nonatomic) NSString *title;

/*
 * @param text (*optional*) Text for the ad.
 */
@property(copy, nonatomic) NSString *text;

/*
 * @param icon (*optional*) Image of an app icon or other icon (small icon such as 80px).
 */
@property(copy, nonatomic) NSURL *icon;

/*
 * @param mainImage (*optional*) Larger main image, such as screenshot of an app.
 */
@property(copy, nonatomic) NSURL *mainImage;

/*
 * @param privacyIcon (*optional*) Privacy icon.
 */
@property(copy, nonatomic)  NSURL *privacyIcon;

/*
 * @param callToActionText (*optional*) Text to put on a button that a user will click.
 */
@property(copy, nonatomic) NSString *callToActionText;

@end
