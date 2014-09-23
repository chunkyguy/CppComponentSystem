//
//  HS_Mesh.h
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Mesh__
#define __HitSoccer__HS_Mesh__
#include <functional>
#include <OpenGLES/ES2/gl.h>
#include <GLKit/GLKMath.h>

/** A drawable entity. You rarely ever need to create a Mesh by hand
 * Ususally there should be other classes like TextureAtlas or SpriteFactory that
 * create a Mesh object.
 */
class Mesh {
public:

    /** Create a Mesh 
     * @param drawIndex Index inside a MeshMemory
     * @param vertexCount Number of vertices for this mesh.
     */
    Mesh(
         const GLint drawIndex = 0,
         const GLsizei vertexCount = 0,
         const GLKVector4 &color = GLKVector4Make(1.0f, 1.0f, 1.0f, 1.0f)
         );
    
    GLKVector4 GetColor() const;
    
    /** Send a draw command to the GPU */
    void Draw() const;
    
private:
    GLsizei vertexCount_; /* number of vertex */
    GLint drawIndex_; /* index within a MeshMemory */
    GLKVector4 color_;
};

inline GLKVector4 Mesh::GetColor() const
{
    return color_;
}


/** MeshData for a 2D sprite with each vertex having a position
 */
union MeshData {
    struct Vertex {
        GLKVector2 position;
    } vertex[4];
    GLfloat data[8];
};

MeshData MeshDataWithSize(const GLKVector2 &size);

/** MeshMemory refers to a memory segment on the GPU RAM */
class MeshMemory {
public:
    /** Create a empty MeshMemory */
    MeshMemory();
    
    /** Release a MeshMemory */
    ~MeshMemory();
    
    /** Make the MeshMemory ready to use */
    bool Load();
    
    /** Allocate a size and format it for use 
     * @param size The size to be allocated.
     * @param data The data to be filled in the memory.
     * @param format The callback to implement the formatting of the memory
     */
    void Allocate(const GLsizeiptr size,
                  const GLfloat *data,
                std::function<void()> format);

    /** Enable the memory for rendering */
    void Enable() const;
    
private:
    GLuint vbo_;
    GLuint vao_;
};

#endif /* defined(__HitSoccer__HS_Mesh__) */
