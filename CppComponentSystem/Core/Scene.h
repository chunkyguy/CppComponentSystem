//
//  Scene.h
//  CppComponentSystem
//
//  Created by Sid on 25/08/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__Scene__
#define __CppComponentSystem__Scene__
#include <map>
#include "Camera.h"
#include "Shader.h"
#include "Actor.h"
#include "Trigger.h"
#include "Sprite.h"
#include "CommonTypes.h"
#include "Shader.h"
#include "Mesh.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "CustomComponent.h"
#include "ContainerComponent.h"

#pragma mark - Scene -

/** The game play scene. A player is going to spend most of the fun time here */
class Scene : public GameObject <
ContainerComponent<
CustomComponent,
RenderComponent
>> {
public:

    /** Create empty scene */
    Scene();
    
    /** Load the scene */
    void Load(const GLKVector2 &screen);
    
    /** Unload the scene */
    void Unload();
    
    /** Update the scene
     * @param dt Time in ms.
     */
    void Update(const int dt);
    
    /** Render the scene */
    void Render();
    
    
private:
    void LoadShader();
    void LoadMesh();
    void LoadEntities();
    void LoadCamera(const GLKVector2 &screen);
    void LoadGL();
    
    Actor ninja_;
    Trigger hiddenBonus_;
    Sprite background_;

    Shader shader_;
    Camera camera_;
    Uniform uniform_;
    
    MeshMemory meshMem_;
    std::map<int, Mesh> meshMap_;
};

#endif /* defined(__CppComponentSystem__Scene__) */
