//
//  WeatherforGazelleGazelleView.h
//  WeatherforGazelle
//
//  Created by wizages on 04/14/2016.
//  Copyright (c) wizages. All rights reserved.
//

#import <objc/runtime.h>

@interface WeatherforGazelleGazelleView : UIView
/**
* If you need to change the background color of the block view
* this is where you would change it
*/
- (UIColor *)presentationBackgroundColor;

/**
* This is called after a user taps on the presented views icon image
* You don't need to do anything except tell it what to do
*/
- (void)handleActionForIconTap;
@end


@interface DayForecast : NSObject
@property (nonatomic, copy) NSString* high;                             //@synthesize high=_high - In the implementation block
@property (nonatomic, copy) NSString* low;                              //@synthesize low=_low - In the implementation block               //@synthesize icon=_icon - In the implementation block
@property (assign, nonatomic) unsigned long long dayOfWeek;              //@synthesize dayOfWeek=_dayOfWeek - In the implementation block
@property (assign, nonatomic) unsigned long long dayNumber;    
@end

@interface HourlyForecast : NSObject 
@property (nonatomic,copy) NSString * time;                             //@synthesize time=_time - In the implementation block
@property (assign,nonatomic) long long hourIndex;                       //@synthesize hourIndex=_hourIndex - In the implementation block
@property (nonatomic,copy) NSString * detail;                           //@synthesize detail=_detail - In the implementation block
@end

@interface City : NSObject
@property (nonatomic, retain) NSArray* dayForecasts;
@property (nonatomic, retain) NSArray* hourlyForecasts;
@property(nonatomic) unsigned long long conditionCode;
-(void)update;
- (id)temperature;
- (id)updateTime;
@property(copy, nonatomic) NSString *name;
@end

@interface WeatherPreferences : NSObject
+ (id)sharedPreferences;
- (id)localWeatherCity;
- (void)setLocalWeatherEnabled:(BOOL)arg1;
- (BOOL)isCelsius;
@end

@interface WeatherLocationManager
+ (id)sharedWeatherLocationManager;
- (void)setLocationTrackingActive:(BOOL)arg1;
- (void)setLocationTrackingReady:(BOOL)arg1 activelyTracking:(BOOL)arg2;
-(void)setLocationTrackingReady:(BOOL)arg1 activelyTracking:(BOOL)arg2 watchKitExtension:(id)arg3;
- (void)setDelegate:(id)arg1;
- (id)location;
- (BOOL)locationTrackingIsReady;
@end

@interface LocationUpdater
+ (id)sharedLocationUpdater;
- (void)updateWeatherForLocation:(id)arg1 city:(id)arg2;
- (void)handleCompletionForCity:(id)arg1 withUpdateDetail:(unsigned long long)arg2;
@end

@implementation UIImage (Colored)

- (UIImage *)changeImageColor:(UIColor *)color {
    UIImage *img = self;
    // begin a new image context, to draw our colored image onto
    UIGraphicsBeginImageContextWithOptions(img.size, NO, [UIScreen mainScreen].scale);
    
    // get a reference to that context we created
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    // set the fill color
    [color setFill];
    
    // translate/flip the graphics context (for transforming from CG* coords to UI* coords
    CGContextTranslateCTM(context, 0, img.size.height);
    CGContextScaleCTM(context, 1.0, -1.0);
    
    // set the blend mode to color burn, and the original image
    CGContextSetBlendMode(context, kCGBlendModeNormal);
    CGRect rect = CGRectMake(0, 0, img.size.width, img.size.height);
    CGContextDrawImage(context, rect, img.CGImage);
    
    // set a mask that matches the shape of the image, then draw (color burn) a colored rectangle
    CGContextClipToMask(context, rect, img.CGImage);
    CGContextAddRect(context, rect);
    CGContextDrawPath(context,kCGPathFill);
    
    // generate a new UIImage from the graphics context we drew onto
    UIImage *coloredImg = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    //return the color-burned image
    return coloredImg;
}

@end
