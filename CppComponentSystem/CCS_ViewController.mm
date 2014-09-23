//
//  CCS_ViewController.m
//  CppComponentSystem
//
//  Created by Sid on 25/08/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#import "CCS_ViewController.h"
#import "Scene.h"

@interface CCS_ViewController () {
    BOOL _sceneLoaded;
    Scene _scene;
    GLKVector2 _screen;
}
@property (strong, nonatomic) EAGLContext *context;

@end

@implementation CCS_ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    /* setup OpenGL context */
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    NSAssert(_context, @"Failed to create ES context");
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormatNone;
    
    [EAGLContext setCurrentContext:self.context];
    
    self.preferredFramesPerSecond = 30;
    _sceneLoaded = NO;
}

- (void)dealloc
{    
    _scene.Unload();
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    
    if ([self isViewLoaded] && ([[self view] window] == nil)) {
        self.view = nil;
        
        _scene.Unload();
        
        if ([EAGLContext currentContext] == self.context) {
            [EAGLContext setCurrentContext:nil];
        }
        self.context = nil;
    }
}


#pragma mark - GLKView and GLKViewController delegate methods

- (void)update
{
    if (!_sceneLoaded) {
        _screen.x = CGRectGetWidth(self.view.bounds);
        _screen.y = CGRectGetHeight(self.view.bounds);
        _scene.Load(_screen);
        _sceneLoaded = YES;
    }
    
    _scene.Update(self.timeSinceLastUpdate * 1000);
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    if (_sceneLoaded) {
        _scene.Render();
    }
}

@end
