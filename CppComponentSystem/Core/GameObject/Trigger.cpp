//
//  Trigger.cpp
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Trigger.h"

void Trigger::Load(const Transform &trans)
{
    /* config transform component */
    transform_ = trans;
    
    /* config custom component */
    customUpdate_ = std::bind(&Trigger::Update, this, std::placeholders::_1);
}

void Trigger::Update(const int dt)
{
    /* TODO: apply physics update */
}
