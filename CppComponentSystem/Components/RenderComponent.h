//
//  RenderComponent.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__RenderComponent__
#define __CppComponentSystem__RenderComponent__
#include "Renderer.h"

/** Add rendering functionality to a GameObject. */
class RenderComponent {
public:
    
    void Render(const Uniform &uniform, const Camera &camera) const;
    
protected:
    Renderer renderer_;
};

inline void RenderComponent::Render(const Uniform &uniform, const Camera &camera) const
{
    renderer_.Render(uniform, camera);
}

#endif /* defined(__CppComponentSystem__RenderComponent__) */
