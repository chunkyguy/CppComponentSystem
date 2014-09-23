//
//  Actor.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__Actor__
#define __CppComponentSystem__Actor__
#include "GameObject.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "CustomComponent.h"

class Actor : public GameObject <TransformComponent, PhysicsComponent, RenderComponent, CustomComponent> {
public:
    void Load(const Transform &trans, const Mesh &mesh);
    void Update(const int dt);
};

#endif /* defined(__CppComponentSystem__Actor__) */
