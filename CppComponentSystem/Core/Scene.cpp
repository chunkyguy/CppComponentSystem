//
//  Scene.cpp
//  CppComponentSystem
//
//  Created by Sid on 25/08/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#include "Scene.h"
#include <iostream>
#include "FileSystem.h"

enum ContainerIndex {
    Custom = 0,
    Render = 1
};

#pragma mark - Scene -
Scene::Scene()
{}

void Scene::Load(const GLKVector2 &screen)
{
    LoadShader();
    LoadMesh();
    LoadEntities();
    LoadCamera(screen);
    LoadGL();
}

void Scene::LoadEntities()
{
    /* load entities */
    background_.Load(Transform(GLKVector2Make(0.0f, 0.0f)), meshMap_[0]);
    std::get<ContainerIndex::Custom>(children_).push_back(&background_);
    std::get<ContainerIndex::Render>(children_).push_back(&background_);
    
    ninja_.Load(Transform(GLKVector2Make(0.0f, 0.0f)), meshMap_[1]);
    std::get<ContainerIndex::Custom>(children_).push_back(&ninja_);
    std::get<ContainerIndex::Render>(children_).push_back(&ninja_);
    
    hiddenBonus_.Load(Transform());
    std::get<ContainerIndex::Custom>(children_).push_back(&hiddenBonus_);
}

void Scene::LoadCamera(const GLKVector2 &screen)
{
    /* set camera */
    camera_.SetFocusArea(screen);
    camera_.SetZoom(1.0f);
}

void Scene::LoadGL()
{
    /* set default GL state */
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    /* fill screen with green color of the grass */
    glClearColor(93.0f/255.0f, 146.0f/255.0f, 55.0f/255.0f, 1.0f);
}

void Scene::LoadShader()
{
    bool status = shader_.Load(File("color_shader", "vsh"), File("color_shader", "fsh"), [](GLuint program) {
        /* bind shader attributes */
        glBindAttribLocation(program, VertexAttributePosition, "av4o_Position");
    }, [&](GLuint program) {
        /* bind uniform locations.*/
        uniform_.um4k_Modelviewprojection = glGetUniformLocation(program, "um4k_Modelviewprojection");
        uniform_.uv4k_Color = glGetUniformLocation(program, "uv4k_Color");
    });
    assert(status);
}

void Scene::LoadMesh()
{
    int meshCount = 2;
    
    /* create buffer */
    std::size_t meshListDataSize = sizeof(MeshData) * meshCount;
    GLfloat *meshListData = new GLfloat[meshListDataSize];
    
    /* generate Mesh map */
    MeshData meshData[2];
    meshData[0] = MeshDataWithSize(GLKVector2Make(200.0, 200.0));
    meshData[1] = MeshDataWithSize(GLKVector2Make(100.0, 100.0));
    
    GLKVector4 meshColors[2] = {
        {1.0f, 1.0f, 0.0f, 1.0f},
        {0.0f, 1.0f, 1.0f, 1.0f}
    };
    
    for (int mesh = 0; mesh < meshCount; ++mesh) {
        
        memcpy(&meshListData[mesh * 8], meshData[mesh].data, sizeof(MeshData));
        
        meshMap_[mesh] = Mesh(
                             mesh * 4,
                             4,
                              meshColors[mesh]
                             );
    }
    
    /* push mesh data to the mesh memory */
    meshMem_.Load();
    meshMem_.Allocate(meshListDataSize, meshListData, []{
        
        glEnableVertexAttribArray(VertexAttributePosition);
        glVertexAttribPointer(VertexAttributePosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
        
    });
    
    /* release buffer */
    delete [] meshListData;
    meshListData = nullptr;
}

void Scene::Unload()
{
}

void Scene::Update(const int dt)
{
    /* update all custom components */
    for (auto customComponent : std::get<ContainerIndex::Custom>(children_)) {
        customComponent->Update(dt);
    }
}

void Scene::Render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* bind all pieces to the GL pipeline */
    meshMem_.Enable();
    shader_.Enable();
    
    /* render all render components */
    for (const auto renderComponent : std::get<ContainerIndex::Render>(children_)) {
        renderComponent->Render(uniform_, camera_);
    }
}
