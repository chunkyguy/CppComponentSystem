//
//  HS_Shader.h
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_Shader__
#define __HitSoccer__HS_Shader__
#include <functional>
#include <OpenGLES/ES2/gl.h>
#include "FileSystem.h"

/** Shader object */
class Shader {
public:
    /** Create an empty Shader */
    Shader();
    
    /** Destroy a Shader */
    ~Shader();
    
    /** Load a shader for use 
     * Compiles + Link the shader
     * @param vshFile Vertex shader file
     * @param fshFile Fragment shader file
     * @param bindAttribCompletion Callback to bind vertex attributes to the shader
     * @param bindUniformCompletion Callback to bind uniform attributes to the shader
     * @return status.
     */
    bool Load(const File &vshFile, const File &fshFile,
              std::function<void(GLuint)> bindAttribCompletion,
              std::function<void(GLuint)> bindUniformCompletion);

    /** Enable shader for rendering */
    void Enable() const;
        
private:
    GLuint program_;
};

#endif /* defined(__HitSoccer__HS_Shader__) */
