//
//  Trigger.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__Trigger__
#define __CppComponentSystem__Trigger__
#include "GameObject.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
#include "CustomComponent.h"

class Trigger : public GameObject<TransformComponent, PhysicsComponent, CustomComponent> {
public:
    void Load(const Transform &trans);
    void Update(const int dt);
};

#endif /* defined(__CppComponentSystem__Trigger__) */
