#import <AppKit/AppKit.h>
#import "RhpChecker.h"

@interface AppController : NSObject <RhpCheckerDelegate> {
	// YES if currently idle, NO if checking
	BOOL ready;
	BOOL menuEnabled;
	
	// the status text to display
	NSString *statusLine;
	
	// the text to display on the "go to site" link
	NSString *resultLine;
	
	// the login status text
	NSString *loginLine;
	
	NSAttributedString *loginWindowText;
	
	// status bar item
	NSStatusItem *statusItem;
	
	// the RHP checker object
	RhpChecker *rhpChecker;

	// how long to wait between checks
	NSTimeInterval interval;
	
	// last check time (time finished checking)
	NSDate *lct;
	
	// timer, for timing :)
	NSTimer *timer;
	
	// status menu object
	IBOutlet NSMenu *statusMenu;
	
	// login window
	IBOutlet NSWindow *loginWindow;
}

@property BOOL ready;
@property (readonly) BOOL pulldown;
@property BOOL menuEnabled;
@property (copy) NSString *statusLine;
@property (copy) NSString *resultLine;
@property (copy) NSString *loginLine;
@property (copy) NSAttributedString *loginWindowText;


// the available UI actions
- (IBAction)goToSite:(id)sender;
- (IBAction)openInSafari:(id)sender;

// UI update methods
- (void)updateResult;
- (void)updateStatus;

- (void)prepareLoginWindow;
- (void)showLoginWindow;

// timer methods
- (void)timerRoutine:(NSTimer *)timer;
- (void)schedule;
- (void)reschedule;

@end
