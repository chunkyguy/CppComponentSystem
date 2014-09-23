//
//  HS_Stringify.h
//  HitSoccer
//
//  Created by Sid on 21/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Stringify__
#define __HitSoccer__HS_Stringify__
#include <iosfwd>
#include <GLKit/GLKMath.h>
/** print external non-fundamental types */
std::ostream &operator<<(std::ostream &os, const GLKVector2 &vec2);
std::ostream &operator<<(std::ostream &os, const GLKVector4 &vec4);
std::ostream &operator<<(std::ostream &os, const GLKMatrix4 &mat4);

#endif /* defined(__HitSoccer__HS_Stringify__) */
