//
//  ChimpKit.h
//  ChimpKit2
//
//  Created by Amro Mousa on 11/19/10.
//  Copyright 2011 MailChimp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBJson.h"

@class ChimpKit;

@protocol ChimpKitDelegate <NSObject>

@optional
- (void)ckRequestSucceeded:(ChimpKit *)ckRequest;

@optional
- (void)ckRequestFailed:(NSError *)error;

@optional
- (void)ckRequestFailed:(ChimpKit *)ckRequest andError:(NSError *)error;

@end

@interface ChimpKit : NSOperation {
@private    
    id<ChimpKitDelegate> _delegate;
    
    NSString *_apiUrl;
    NSString *_apiKey;

    id _userInfo;

    NSString *_responseString;
    NSInteger _responseStatusCode;
    NSError *_error;    
    
    NSURLConnection *_connection;
    NSMutableData *_responseData;
}

@property (assign, readwrite) id<ChimpKitDelegate> delegate;
@property (nonatomic, retain) id userInfo;

@property (nonatomic, copy) NSString *apiUrl;
@property (nonatomic, copy) NSString *apiKey;

@property (nonatomic, retain) NSURLConnection *connection;
@property (nonatomic, retain) NSMutableData *responseData;

@property (nonatomic, readonly) NSString *responseString;
@property (nonatomic, readonly) NSInteger responseStatusCode;
@property (nonatomic, readonly) NSError *error;

+ (void)setTimeout:(NSUInteger)tout;

-(id)initWithDelegate:(id)aDelegate andApiKey:(NSString *)key;
-(void)callApiMethod:(NSString *)method withParams:(NSDictionary *)params;
- (void)cancel;

@end