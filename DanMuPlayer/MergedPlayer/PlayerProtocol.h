//
//  PlayerProtocol.h
//  JSCats
//
//  Created by zfu on 2018/11/4.
//  Copyright © 2018 zfu. All rights reserved.
//

#ifndef PlayerProtocol_h
#define PlayerProtocol_h
#import <UIKit/UIKit.h>
#import "./TopPanel/PanelControlProtocol.h"
#import "DMPlaylist.h"

@protocol PlayerImplementProtocol <NSObject>
- (void)onPause;
- (void)onPlay;
- (void)onEnd;
- (void)onError:(NSString*)msg;
- (void)updateProgress:(NSTimeInterval)current playableTime:(NSTimeInterval)playableTime buffering:(BOOL)buffering total:(NSTimeInterval)total;
@optional
- (void)bufferring;
- (void)stopBufferring;
- (void)onVideoSizeChanged:(CGSize)size;
- (void)onVideoFPSChanged:(CGFloat)fps;
@end

@protocol PlayerProtocol <NSObject>
- (void)play;
- (void)pause;
- (void)empty;
- (void)stop;
- (void)seekToTime:(NSTimeInterval)time;
- (NSTimeInterval)currentTime;
- (NSTimeInterval)duration;
- (NSTimeInterval)playableTime;
- (void)playVideo:(NSString*)url
        withTitle:(NSString*)title
          withImg:(NSString*)img
   withDesciption:(NSString*)desc
          options:(NSMutableDictionary*)options
              mp4:(BOOL)mp4
   withResumeTime:(CGFloat)resumeTime;
@property (nonatomic, readwrite, strong) UIView *videoView;
@property (nonatomic, readwrite, assign) CGSize videoSize;
@property (nonatomic, readwrite, weak) id<PlayerImplementProtocol> delegate;
@optional
- (void)changeSpeedMode:(PlaySpeedMode)speedMode;
- (void)changeScaleMode:(PlayScaleMode)scaleMode;
- (void)changeDanmuMode:(PlayDanMuMode)danmuMode;
@end

#endif /* PlayerProtocol_h */
