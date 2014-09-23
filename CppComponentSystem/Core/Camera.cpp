//
//  HS_Camera.cpp
//  HitSoccer
//
//  Created by Sid on 15/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Camera.h"

Camera::Camera() :
area_(GLKVector2Make(480.0f, 320.0f)),
eye_(GLKVector3Make(0.0f, 0.0f, 1.0f)),
center_(GLKVector3Make(0.0f, 0.0f, 0.0f)),
up_(GLKVector3Make(0.0f, 1.0f, 0.0f)),
projectionMatrix_(GLKMatrix4Identity),
viewMatrix_(GLKMatrix4Identity),
zoom_(1.0f),
pan_(GLKVector2Make(0.0f, 0.0f))
{
    UpdateProjection();
    UpdateView();
}

void Camera::UpdateProjection()
{
    projectionMatrix_ = GLKMatrix4MakeOrtho(-area_.x/(2.0f * zoom_) + pan_.x,
                                            area_.x/(2.0f * zoom_) + pan_.x,
                                            -area_.y/(2.0f * zoom_) + pan_.y,
                                            area_.y/(2.0f * zoom_) + pan_.y,
                                            0.1f, 100.0f);
}

void Camera::UpdateView()
{
    viewMatrix_ = GLKMatrix4MakeLookAt(eye_.x, eye_.y, eye_.z,
                                       center_.x, center_.y, center_.z,
                                       up_.x, up_.y, up_.z);
}
