//
//  Actor.cpp
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Actor.h"

void Actor::Load(const Transform &trans, const Mesh &mesh)
{
    /* config transform component */
    transform_ = trans;

    /* config renderer component */
    renderer_.SetMesh(mesh);

    /* config custom component */
    customUpdate_ = std::bind(&Actor::Update, this, std::placeholders::_1);
}

void Actor::Update(const int dt)
{
    /* TODO: apply physics update */
    renderer_.SetModelMatrix(transform_.GetModelMatrix());
}

