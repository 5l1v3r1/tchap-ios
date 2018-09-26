/*
 Copyright 2014 OpenMarket Ltd
 Copyright 2017 Vector Creations Ltd
 Copyright 2018 New Vector Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <MatrixKit/MatrixKit.h>

#import "RoomTitleView.h"

#import "RoomPreviewData.h"

#import "UIViewController+RiotSearch.h"

@class RoomViewController;

/**
 `RoomViewController` delegate.
 */
@protocol RoomViewControllerDelegate <NSObject>

/**
 Tells the delegate that the user wants to open the room details (members, files, settings).
 
 @param roomViewController the `RoomViewController` instance.
 */
- (void)roomViewControllerShowRoomDetails:(RoomViewController *)roomViewController;

/**
 Tells the delegate that the user wants to display the details of a room member.
 
 @param roomViewController the `RoomViewController` instance.
 @param roomMember the selected member
 */
- (void)roomViewController:(RoomViewController *)roomViewController showMemberDetails:(MXRoomMember *)roomMember;

/**
 Tells the delegate that the user wants to display another room.
 
 @param roomViewController the `RoomViewController` instance.
 @param roomID the selected roomId
 */
- (void)roomViewController:(RoomViewController *)roomViewController showRoom:(NSString *)roomID;

/**
 Tells the delegate that the user wants to join room from room preview.
 
 @param roomViewController the `RoomViewController` instance.
 */
- (void)roomViewControllerPreviewDidTapJoin:(RoomViewController *)roomViewController;

/**
 Tells the delegate that the user wants to cancel the room preview.
 
 @param roomViewController the `RoomViewController` instance.
 */
- (void)roomViewControllerPreviewDidTapCancel:(RoomViewController *)roomViewController;

@end

@interface RoomViewController : MXKRoomViewController <UISearchBarDelegate, UIGestureRecognizerDelegate, RoomTitleViewTapGestureDelegate>

// The preview header
@property (weak, nonatomic) IBOutlet UIView *previewHeaderContainer;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *previewHeaderContainerTopConstraint;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *previewHeaderContainerHeightConstraint;

// The jump to last unread banner
@property (weak, nonatomic) IBOutlet UIView *jumpToLastUnreadBannerContainer;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *jumpToLastUnreadBannerContainerTopConstraint;
@property (weak, nonatomic) IBOutlet UIButton *jumpToLastUnreadButton;
@property (weak, nonatomic) IBOutlet UILabel *jumpToLastUnreadLabel;
@property (weak, nonatomic) IBOutlet UIButton *resetReadMarkerButton;

/**
 Preview data for a room invitation received by email, or a link to a room.
 */
@property (nonatomic, readonly) RoomPreviewData *roomPreviewData;

/**
 Tell whether a badge must be added next to the chevron (back button) showing number of unread rooms.
 YES by default.
 */
@property (nonatomic) BOOL showMissedDiscussionsBadge;

/**
 The delegate for the view controller.
 */
@property (weak, nonatomic) id<RoomViewControllerDelegate> delegate;

/**
 Display the preview of a room that is unknown for the user.

 This room can come from an email invitation link or a simple link to a room.

 @param roomPreviewData the data for the room preview.
 */
- (void)displayRoomPreview:(RoomPreviewData*)roomPreviewData;

/**
 Action used to handle some buttons.
 */
- (IBAction)onButtonPressed:(id)sender;

/**
 Creates and returns a new `RoomViewController` object.
 
 @return An initialized `RoomViewController` object.
 */
+ (instancetype)instantiate;

@end

