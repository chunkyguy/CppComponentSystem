//
//  Sprite.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__Sprite__
#define __CppComponentSystem__Sprite__
#include "GameObject.h"
#include "TransformComponent.h"
#include "CustomComponent.h"
#include "RenderComponent.h"

class Sprite : public GameObject<TransformComponent, RenderComponent, CustomComponent> {
public:
    void Load(const Transform &trans, const Mesh &mesh);
    void Update(const int dt);
};

#endif /* defined(__CppComponentSystem__Sprite__) */
