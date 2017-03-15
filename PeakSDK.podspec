Pod::Spec.new do |s|
s.name = 'PeakSDK'
s.version = '0.17.6'
s.summary = 'Our mediation technology is built to truly make each ad network and demand source compete, dynamically, for each ad call, with out ANY WORK by you.'
s.homepage = 'http://peakmediation.com'
s.license = 'PeakSDK'
s.authors = { 'Peak Mediation, Inc' => 'support@peakmediation.com' }
s.source = { :git => 'https://github.com/peakmediation/Peak-Mediation-iOS-SDK.git' }
s.requires_arc = true
s.platform = :ios, '8.0'
s.resources = 'PeakSDK.embeddedframework/Resources/*.*'
s.frameworks = 'AdSupport', 'AudioToolbox', 'AVFoundation', 'CFNetwork', 'CoreFoundation', 'CoreGraphics', 'CoreLocation', 'CoreMedia', 'CoreTelephony', 'EventKit', 'EventKitUI', 'MediaPlayer', 'MessageUI', 'MobileCoreServices', 'SafariServices', 'Security', 'Social', 'StoreKit', 'SystemConfiguration', 'UIKit', 'QuartzCore', 'WebKit'
s.libraries = 'c++', 'sqlite3', 'xml2', 'z'
s.vendored_frameworks = 'PeakSDK.embeddedframework/PeakSDK.framework', 'PeakSDK.embeddedframework/PKFlurry.framework', 'PeakSDK.embeddedframework/PKMyTarget.framework', 'PeakSDK.embeddedframework/PKAvoCarrot.framework', 'PeakSDK.embeddedframework/PKLeadbolt.framework', 'PeakSDK.embeddedframework/PKNativeX.framework', 'PeakSDK.embeddedframework/PKInMobi.framework', 'PeakSDK.embeddedframework/PKYandex.framework', 'PeakSDK.embeddedframework/PKAppLovin.framework', 'PeakSDK.embeddedframework/PKVungle.framework', 'PeakSDK.embeddedframework/PKAdColony.framework', 'PeakSDK.embeddedframework/PKUnityAds.framework', 'PeakSDK.embeddedframework/PKMoPub.framework', 'PeakSDK.embeddedframework/PKMobFox.framework'
end
