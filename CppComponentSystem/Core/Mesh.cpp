//
//  HS_Mesh.cpp
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Mesh.h"
#include <OpenGLES/ES2/glext.h>

#pragma mark - MeshMemory -
MeshMemory::MeshMemory() :
vao_(0),
vbo_(0)
{
}

bool MeshMemory::Load()
{
    glGenVertexArraysOES(1, &vao_);
    glGenBuffers(1, &vbo_);
    return true;
}

MeshMemory::~MeshMemory()
{
    if (vbo_) {
        glDeleteBuffers(1, &vbo_);
        vbo_ = 0;
    }
    if (vao_) {
        glDeleteVertexArraysOES(1, &vao_);
        vao_ = 0;
    }
}

void MeshMemory::Allocate(const GLsizeiptr size,
                        const GLfloat *data,
                        std::function<void()> format)
{
    glBindVertexArrayOES(vao_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    format();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArrayOES(0);
}

void MeshMemory::Enable() const
{
    glBindVertexArrayOES(vao_);
}

#pragma mark - Mesh -
Mesh::Mesh(
           const GLint drawIndex,
           const GLsizei vertexCount,
           const GLKVector4 &color
           ) :
drawIndex_(drawIndex),
vertexCount_(vertexCount),
color_(color)
{}

void Mesh::Draw() const
{
    glDrawArrays(GL_TRIANGLE_STRIP, drawIndex_, vertexCount_);
}

#pragma mark - MeshData -
MeshData MeshDataWithSize(const GLKVector2 &size)
{
    MeshData meshData;
    meshData.vertex[0].position = GLKVector2Make(-size.x/2.0, size.y/2.0);
    meshData.vertex[1].position = GLKVector2Make(-size.x/2.0, -size.y/2.0);
    meshData.vertex[2].position = GLKVector2Make(size.x/2.0, size.y/2.0);
    meshData.vertex[3].position = GLKVector2Make(size.x/2.0, -size.y/2.0);
    return meshData;
}
