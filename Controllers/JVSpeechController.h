// Created by Mike Shields on 10/9/05.

@interface JVSpeechController : NSObject {
	NSMutableArray *_speechQueue;
	NSArray *_synthesizers;
	NSMutableArray *_voiceArray;
}
+ (JVSpeechController*) sharedSpeechController;
- (void) startSpeakingString:(NSString *) string usingVoice:(NSString *) voice;
- (void) startSpeakingString:(NSString *) string forUser:(NSString *)name;
@end
