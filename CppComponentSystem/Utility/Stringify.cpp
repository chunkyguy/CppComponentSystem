//
//  HS_Stringify.cpp
//  HitSoccer
//
//  Created by Sid on 21/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Stringify.h"
#include <ostream>

std::ostream &operator<<(std::ostream &os, const GLKVector2 &vec2)
{
    os << "{" << vec2.x << ", " << vec2.y << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const GLKVector4 &vec4)
{
    os << "{" << vec4.x << ", " << vec4.y << ", " << vec4.z << ", " << vec4.w << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const GLKMatrix4 &mat4)
{
    os
    << "\n{" << mat4.m00 << " " << mat4.m01 << " " << mat4.m02 << " " << mat4.m03 << "}"
    << "\n{" << mat4.m10 << " " << mat4.m11 << " " << mat4.m22 << " " << mat4.m33 << "}"
    << "\n{" << mat4.m20 << " " << mat4.m21 << " " << mat4.m22 << " " << mat4.m33 << "}"
    << "\n{" << mat4.m30 << " " << mat4.m31 << " " << mat4.m22 << " " << mat4.m33 << "}"
    << "\n";
    return os;
}
