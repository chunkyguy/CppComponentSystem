//
//  HS_Transform.cpp
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Transform.h"

Transform::Transform(const GLKVector2 &position, const Degree rotation) :
position_(position),
rotation_(rotation)
{}

GLKMatrix4 Transform::GetModelMatrix() const
{
    return GLKMatrix4Multiply(GLKMatrix4MakeTranslation(position_.x, position_.y, 0.0f), GLKMatrix4MakeRotation(GLKMathDegreesToRadians(rotation_), 0.0f, 0.0f, 1.0f));

}
