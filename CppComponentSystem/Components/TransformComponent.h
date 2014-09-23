//
//  TransformComponent.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__TransformComponent__
#define __CppComponentSystem__TransformComponent__
#include "Transform.h"

/** TransformComponent adds functionality to have a transform object in a
 * GameObject
 */
class TransformComponent {
public:
    /** Create default Transform component */
    TransformComponent();
    
protected:
    Transform transform_;
};

inline TransformComponent::TransformComponent() :
transform_()
{}
#endif /* defined(__CppComponentSystem__TransformComponent__) */
