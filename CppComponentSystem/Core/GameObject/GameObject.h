//
//  GameObject.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__GameObject__
#define __CppComponentSystem__GameObject__

template <typename... Component>
class GameObject : public Component... {
public:
    GameObject() :
    Component()...
    {}
    
    GameObject(Component... component) :
    Component(component)...
    {}
};

#endif /* defined(__CppComponentSystem__GameObject__) */
