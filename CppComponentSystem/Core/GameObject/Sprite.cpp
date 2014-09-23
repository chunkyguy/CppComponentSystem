//
//  Sprite.cpp
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Sprite.h"

void Sprite::Load(const Transform &trans, const Mesh &mesh)
{
    /* config transform component */
    transform_ = trans;
    
    /* config renderer component */
    renderer_.SetMesh(mesh);
    
    /* config custom component */
    customUpdate_ = std::bind(&Sprite::Update, this, std::placeholders::_1);
}

void Sprite::Update(const int dt)
{
    renderer_.SetModelMatrix(transform_.GetModelMatrix());
}
