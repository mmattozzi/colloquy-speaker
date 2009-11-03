// Created by Mike Shields on 10/9/05.

#import "JVSpeechController.h"

@implementation JVSpeechController
+ (JVSpeechController*) sharedSpeechController {
	static JVSpeechController *sharedSpeechController = nil;
	if( ! sharedSpeechController ) sharedSpeechController = [[JVSpeechController alloc] init];
	return sharedSpeechController;
}

- (id) init {
	if( ( self = [super init] ) ) {
		_speechQueue = [[NSMutableArray alloc] initWithCapacity:15];
		// _synthesizers = [[NSArray alloc] initWithObjects:[[[NSSpeechSynthesizer alloc] initWithVoice:nil] autorelease], [[[NSSpeechSynthesizer alloc] initWithVoice:nil] autorelease], [[[NSSpeechSynthesizer alloc] initWithVoice:nil] autorelease], nil];
		_synthesizers = [[NSArray alloc] initWithObjects:[[[NSSpeechSynthesizer alloc] initWithVoice:nil] autorelease], nil];
		
		for( NSUInteger i = 0; i < [_synthesizers count]; i++ )
			[[_synthesizers objectAtIndex:i] setDelegate:self];
		
		NSArray *_voices = [NSSpeechSynthesizer availableVoices];
		_voiceArray = [[NSMutableArray alloc] initWithCapacity:[_voices count]];
		for (unsigned int i = 0; i < [_voices count]; i++) {
			[_voiceArray addObject:[NSString stringWithString:[_voices objectAtIndex:i]]];
		}
		[_voiceArray removeObject:@"com.apple.speech.synthesis.voice.Bubbles"];
		[_voiceArray removeObject:@"com.apple.speech.synthesis.voice.Organ"];
		
	}

	return self;
}

- (void) dealloc {
	[_speechQueue release];
	[_synthesizers release];
	[_voiceArray release];

	_speechQueue = nil;
	_synthesizers = nil;

	[super dealloc];
}

- (void) startSpeakingString:(NSString *) string forUser:(NSString *)name {
	//NSArray *_voices = [NSSpeechSynthesizer availableVoices];
	//NSMutableArray *voicesMutable = [NSMutableArray arrayWithCapacity:[_voices count]];
	//[voicesMutable addObjectsFromArray:_voices];
	//[voicesMutable removeObject:@"com.apple.speech.synthesis.voice.Bubbles"];
	[self startSpeakingString:string usingVoice:[_voiceArray objectAtIndex:([name hash] % [_voiceArray count])]];
}

- (void) startSpeakingString:(NSString *) string usingVoice:(NSString *) voice {
	for( NSUInteger i = 0; i < [_synthesizers count]; i++ ) {
		NSSpeechSynthesizer *synth = [_synthesizers objectAtIndex:i];
		if( ! [synth isSpeaking] ) {
			if (voice != nil) [synth setVoice:voice];
			[synth setRate:250];
			[synth startSpeakingString:string];
			return;
		}
	}

	// Limit the number of outstanding strings to 15. This will prevent massive amounts of TTS flooding
	// when you get a channel flood or re-connect to a dircproxy server. Remove the oldest string from
	// the queue and then insert the new string onto the end.
	if( [_speechQueue count] > 15 )
		[_speechQueue removeObjectAtIndex:0];

	[_speechQueue addObject:[NSDictionary dictionaryWithObjectsAndKeys:string, @"text", voice, @"voice", nil]];
}

- (void) speechSynthesizer:(NSSpeechSynthesizer *) sender didFinishSpeaking:(BOOL) finishedSpeaking {
	if( [_speechQueue count] ) {
		NSDictionary *nextSpeech = [_speechQueue objectAtIndex:0];
		[nextSpeech retain];
		[_speechQueue removeObjectAtIndex:0];
		if ([nextSpeech objectForKey:@"voice"] != nil) [sender setVoice:[nextSpeech objectForKey:@"voice"]];
		[sender setRate:250];
		[sender startSpeakingString:[nextSpeech objectForKey:@"text"]];
		[nextSpeech release];
	}
}
@end
