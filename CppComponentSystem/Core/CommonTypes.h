//
//  Shader.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__Shader__
#define __CppComponentSystem__Shader__

struct Uniform {
    int um4k_Modelviewprojection;
    int uv4k_Color;
};

/** Vertex attributes */
typedef enum {
    VertexAttributePosition = 0
} VertexAttribute;

/** Different types of angle units */
typedef float Degree;
typedef float Radian;

#endif /* defined(__CppComponentSystem__Shader__) */
