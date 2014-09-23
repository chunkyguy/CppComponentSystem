//
//  HS_Renderer.cpp
//  HitSoccer
//
//  Created by Sid on 21/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Renderer.h"
#include <iostream>
#include "Stringify.h"
#include "Camera.h"

Renderer::Renderer() :
modelMatrix_(GLKMatrix4Identity),
mesh_()
{}

void Renderer::Render(const Uniform &uniform, const Camera &camera) const
{
    glUniform4fv(uniform.uv4k_Color, 1, mesh_.GetColor().v);
    
    GLKMatrix4 modelViewProjectionMatrix = GLKMatrix4Multiply(camera.GetProjectionMatrix(),
                                                              GLKMatrix4Multiply(camera.GetViewMatrix(),
                                                                                 modelMatrix_));
    glUniformMatrix4fv(uniform.um4k_Modelviewprojection, 1, 0, modelViewProjectionMatrix.m);
    mesh_.Draw();
}

