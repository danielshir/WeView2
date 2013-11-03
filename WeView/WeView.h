//
//  WeView.h
//  WeView v2
//
//  Copyright (c) 2013 Charles Matthew Chen. All rights reserved.
//
//  Distributed under the Apache License v2.0.
//  http://www.apache.org/licenses/LICENSE-2.0.html
//

#pragma once

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "UIView+WeView.h"
#import "WeViewBlockLayout.h"
#import "WeViewGridLayout.h"

@class WeViewLayout;

@interface WeView : UIView

#pragma mark - Custom Layouts

// Add subviews with a custom layout which will only apply for these subviews.

- (WeView *)addSubviews:(NSArray *)subviews
             withLayout:(WeViewLayout *)layout;
- (WeView *)addSubview:(UIView *)subview
            withLayout:(WeViewLayout *)layout;

// Add a subview with a custom layout that applies to just that subview.
- (WeViewLayout *)addSubviewWithCustomLayout:(UIView *)subview;

// Add subviews with a horizontal layout that applies to just these subviews.
- (WeViewLayout *)addSubviewsWithHorizontalLayout:(NSArray *)subviews;

// Add subviews with a vertical layout that applies to just these subviews.
- (WeViewLayout *)addSubviewsWithVerticalLayout:(NSArray *)subviews;

// Add subviews with a stack layout that applies to just these subviews.
- (WeViewLayout *)addSubviewsWithStackLayout:(NSArray *)subviews;

// Add subviews with a flow layout that applies to just these subviews.
- (WeViewLayout *)addSubviewsWithFlowLayout:(NSArray *)subviews;

// Add subviews with a block-based layout that applies to just these subviews.
//
// The "layout" block positions and sizes these subviews.
- (WeViewLayout *)addSubviews:(NSArray *)subviews
              withLayoutBlock:(WeViewLayoutBlock)layoutBlock;

// Add subviews with a block-based layout that applies to just these subviews.
//
// The "layout" block positions and sizes these subviews and the "desired size" block
// determines the desired size of these subviews.
- (WeViewLayout *)addSubviews:(NSArray *)subviews
              withLayoutBlock:(WeViewLayoutBlock)layoutBlock
             desiredSizeBlock:(WeViewDesiredSizeBlock)desiredSizeBlock;

// Add a subview with a block-based layout that applies to just that subview.
//
// The "layout" block positions and sizes this subview.
- (WeViewLayout *)addSubview:(UIView *)subview
             withLayoutBlock:(WeViewLayoutBlock)layoutBlock
            desiredSizeBlock:(WeViewDesiredSizeBlock)desiredSizeBlock;

// Add a subview with a block-based layout that applies to just that subview.
//
// The "layout" block positions and sizes this subview and the "desired size" block determines
// the desired size of this subview.
- (WeViewLayout *)addSubview:(UIView *)subview
             withLayoutBlock:(WeViewLayoutBlock)layoutBlock;

// Use this factory method if the size of the cells should be based on their contents.
//
// columnCount: The number of columns in the grid.
// isGridUniform: If true, the layout guarantees that the cell sizes will all be nearly equal.
//                Each column will be as wide as the widest column.
//                Each row will be as tall as the tallest row.
// stretchPolicy: See the GridStretchPolicy enum.
- (WeViewLayout *)addSubviewsWithGridLayout:(NSArray *)subviews
                                columnCount:(int)columnCount
                              isGridUniform:(BOOL)isGridUniform
                              stretchPolicy:(GridStretchPolicy)stretchPolicy;

// Use this factory method if you want to specify a cellSizeHint.
//
// columnCount: The number of columns in the grid.
// isGridUniform: If true, the layout guarantees that the cell sizes will all be nearly equal.
//                Each column will be as wide as the widest column.
//                Each row will be as tall as the tallest row.
// stretchPolicy: See the GridStretchPolicy enum.
// cellSizeHint: The base cell size to use. The cell sizes will not reflect the desired sizes of
//                their contents.
- (WeViewLayout *)addSubviewsWithGridLayout:(NSArray *)subviews
                                columnCount:(int)columnCount
                              isGridUniform:(BOOL)isGridUniform
                              stretchPolicy:(GridStretchPolicy)stretchPolicy
                               cellSizeHint:(CGSize)cellSizeHint;

#pragma mark - Fill & Fit Layouts

// Add a subview with a layout that stretches the subview to fill this view's bounds,
// regardless of its desired size.
- (WeViewLayout *)addSubviewWithFillLayout:(UIView *)subview;

// Add a subview with a layout that stretches the subview to fill this view's bounds, while
// preserving its aspect ratio.
- (WeViewLayout *)addSubviewWithFillLayoutWAspectRatio:(UIView *)subview;

// Add a subview with a layout that stretches the subview to "fit" this view's bounds, while
// preserving its aspect ratio.
//
// In a "fit" layout, the subview will have the largest possible size that exactly fits in its
// superview's bounds.
- (WeViewLayout *)addSubviewWithFitLayoutWAspectRatio:(UIView *)subview;

#pragma mark -

- (void)removeAllSubviews;

- (void)setDebugLayoutOflayouts:(BOOL)value;
- (void)setDebugMinSizeOflayouts:(BOOL)value;

@end
