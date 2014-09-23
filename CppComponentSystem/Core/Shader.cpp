//
//  HS_Shader.cpp
//  HitSoccer
//
//  Created by Sid on 16/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Shader.h"
#include <cassert>
#include <iostream>

static bool CompileShader(GLuint *shader, GLenum type, const File &file)
{
    GLint status;
    std::string sourceStr = file.GetContents();
    //    std::cout << sourceStr << std::endl;
    assert(sourceStr.size()); //Failed to load vertex shader
    const GLchar *source = (GLchar *)sourceStr.c_str();
    
    *shader = glCreateShader(type);
    glShaderSource(*shader, 1, &source, NULL);
    glCompileShader(*shader);
    
#if defined(DEBUG)
    GLint logLength;
    glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetShaderInfoLog(*shader, logLength, &logLength, log);
        std::cout << "Shader compile log:\n" << log << std::endl;
        free(log);
    }
#endif
    
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        glDeleteShader(*shader);
        return false;
    }
    
    return true;
}

static bool LinkProgram(GLuint prog)
{
    GLint status;
    glLinkProgram(prog);
    
#if defined(DEBUG)
    GLint logLength;
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(prog, logLength, &logLength, log);
        std::cout << "Program link log:\n" << log << std::endl;
        free(log);
    }
#endif
    
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    if (status == 0) {
        return false;
    }
    
    return true;
}

__unused static bool ValidateProgram(GLuint prog)
{
    GLint logLength, status;
    
    glValidateProgram(prog);
    glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        GLchar *log = (GLchar *)malloc(logLength);
        glGetProgramInfoLog(prog, logLength, &logLength, log);
        std::cout << "Program validate log:\n" << log << std::endl;
        free(log);
    }
    
    glGetProgramiv(prog, GL_VALIDATE_STATUS, &status);
    if (status == 0) {
        return false;
    }
    
    return true;
}

Shader::Shader() :
program_(0)
{}

Shader::~Shader()
{
    if (program_) {
        glDeleteProgram(program_);
        program_ = 0;
    }
}

bool Shader::Load(const File &vshFile, const File &fshFile,
                  std::function<void(GLuint)> bindAttribCompletion,
                  std::function<void(GLuint)> bindUniformCompletion)
{
    GLuint vertShader, fragShader;
    
    // Create shader program.
    program_ = glCreateProgram();
    
    // Create and compile vertex shader.
    bool status = CompileShader(&vertShader, GL_VERTEX_SHADER, vshFile);
    if (!status) {
        std::cout << "Failed to compile vertex shader" << std::endl;
        return false;
    }
    
    // Create and compile fragment shader.
    status = CompileShader(&fragShader, GL_FRAGMENT_SHADER, fshFile);
    if (!status) {
        std::cout << "Failed to compile fragment shader" << std::endl;
        return false;
    }
    
    // Attach vertex shader to program.
    glAttachShader(program_, vertShader);
    
    // Attach fragment shader to program.
    glAttachShader(program_, fragShader);
    
    // Bind attribute locations.
    // This needs to be done prior to linking.
    bindAttribCompletion(program_);
    
    // Link program.
    status = LinkProgram(program_);
    if (!status) {
        std::cout << "Failed to link program: " << program_ << std::endl;
        
        if (vertShader) {
            glDeleteShader(vertShader);
            vertShader = 0;
        }
        if (fragShader) {
            glDeleteShader(fragShader);
            fragShader = 0;
        }
        if (program_) {
            glDeleteProgram(program_);
            program_ = 0;
        }
        
        return false;
    }

    bindUniformCompletion(program_);
    
    // Release vertex and fragment shaders.
    if (vertShader) {
        glDetachShader(program_, vertShader);
        glDeleteShader(vertShader);
    }
    if (fragShader) {
        glDetachShader(program_, fragShader);
        glDeleteShader(fragShader);
    }
    
    return true;
}

void Shader::Enable() const
{
    glUseProgram(program_);
}

