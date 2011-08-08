/*
 
 Copyright (C) 2011 GUI Cocoa, LLC.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 */

#import <Foundation/Foundation.h>

// notice info
typedef struct ab_signal_info_t {
	
	// file name used for a signal notice
	const char *notice_path;
    
    // notice payload
    unsigned long notice_payload_length;
    void *notice_payload;
    
    // environment info
    unsigned long user_data_length;
    void *user_data;
	
} ab_signal_info_t;
ab_signal_info_t ab_signal_info;

// notice payload keys
extern NSString *ABNotifierOperatingSystemVersionKey;
extern NSString *ABNotifierApplicationVersionKey;
extern NSString *ABNotifierPlatformNameKey;
extern NSString *ABNotifierEnvironmentNameKey;
extern NSString *ABNotifierBundleVersionKey;
extern NSString *ABNotifierExceptionNameKey;
extern NSString *ABNotifierExceptionReasonKey;
extern NSString *ABNotifierCallStackKey;
extern NSString *ABNotifierControllerKey;
extern NSString *ABNotifierExecutableKey;

// notice file extension
extern NSString *ABNotifierNoticePathExtension;

// file flags
extern int ABNotifierNoticeVersion;
extern int ABNotifierSignalNoticeType;
extern int ABNotifierExceptionNoticeType;

/*
 
 Instances of the HTNotice class represent a single crash
 report. It holds all of the properties that get posted to
 Hoptoad.
 
 All of the properties represented as instance variables are
 persisted in the file representation of the object. Those
 that are not are pulled from the HTNotifier at runtime
 (primarily the API key).
 
 */
@interface HTNotice : NSObject {
    NSString *__environmentName;
    NSString *__bundleVersion;
    NSString *__exceptionName;
    NSString *__exceptionReason;
    NSString *__controller;
    NSString *__action;
    NSString *__executable;
    NSDictionary *__environmentInfo;
    NSArray *__callStack;
    NSNumber *__noticeVersion;
}

// create an object representation of notice data
- (id)initWithContentsOfFile:(NSString *)path;
+ (HTNotice *)noticeWithContentsOfFile:(NSString *)path;

// get a string representation of the hoptoad xml payload
- (NSString *)hoptoadXMLString;

@end
