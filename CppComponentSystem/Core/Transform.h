//
//  HS_Transform.h
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Transform__
#define __HitSoccer__HS_Transform__
#include <GLKit/GLKMath.h>
#include "CommonTypes.h"

/** A Transform object */
class Transform {
public:
    /** Create default Transform */
    Transform(const GLKVector2 &position = GLKVector2Make(0.0f, 0.0f),
              const Degree rotation = 0.0f);

    GLKVector2 GetPosition() const;
    
    void SetPosition(const GLKVector2 &position);
    
    /** Get angle in degrees */
    float GetRotation() const;
    
    /** Set rotation in degrees
     * @param rotation Angle in degrees.
     */
    void SetRotation(const Degree rotation);
    
    /** Get the model matrix of the transform to take things from model space to
     * the world space
     */
    GLKMatrix4 GetModelMatrix() const;
    
private:
    GLKVector2 position_;
    Degree rotation_;
};


inline GLKVector2 Transform::GetPosition() const
{
    return position_;
}

inline void Transform::SetPosition(const GLKVector2 &position)
{
    position_ = position;
}

inline float Transform::GetRotation() const
{
    return rotation_;
}

/** Set rotation in degrees
 * @param rotation Angle in degrees.
 */
inline void Transform::SetRotation(const Degree rotation)
{
    rotation_ = rotation;
}

#endif /* defined(__HitSoccer__HS_Transform__) */
