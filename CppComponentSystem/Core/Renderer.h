//
//  HS_Renderer.h
//  HitSoccer
//
//  Created by Sid on 21/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Renderer__
#define __HitSoccer__HS_Renderer__
#include "CommonTypes.h"
#include "Mesh.h"

class Camera;

class Renderer {
public:

    /** Create empty Renderer */
    Renderer();
    
    /** Render the attached mesh
     * @param uniform The uniform variables to be passed to the pipeline.
     * @param camera Apply the camera to the rendering object
     */
    void Render(const Uniform &uniform, const Camera &camera) const;

    /** Set mesh.
     * @param mesh A mesh
     */
    void SetMesh(const Mesh &mesh);
    
    const Mesh &GetMesh() const;
    
    /** Set Model matrix that transforms mesh from object-space to world space.
     * @param modelMatrix The model matrix
     */
    void SetModelMatrix(const GLKMatrix4 &modelMatrix);
    
private:
    GLKMatrix4 modelMatrix_;
    Mesh mesh_;
};

inline void Renderer::SetMesh(const Mesh &mesh)
{
    mesh_ = mesh;
}

inline const Mesh &Renderer::GetMesh() const
{
    return mesh_;
}

inline void Renderer::SetModelMatrix(const GLKMatrix4 &modelMatrix)
{
    modelMatrix_ = modelMatrix;
}

#endif /* defined(__HitSoccer__HS_Renderer__) */
