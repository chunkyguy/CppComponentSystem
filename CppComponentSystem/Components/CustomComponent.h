//
//  CustomComponent.h
//  CppComponentSystem
//
//  Created by Sid on 23/09/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __CppComponentSystem__CustomComponent__
#define __CppComponentSystem__CustomComponent__
#include <functional>

/** Add a custom update function to the GameObject.
 * The CustomUpdate also provides a delta time.
 */
class CustomComponent {
public:
    /** Create an empty CustomComponent */
    CustomComponent();
    void Update(const int dt);
    
protected:
    std::function<void(const int dt)> customUpdate_;
};

inline void CustomComponent::Update(const int dt)
{
    customUpdate_(dt);
}

inline CustomComponent::CustomComponent() :
customUpdate_(nullptr)
{}

#endif /* defined(__CppComponentSystem__CustomComponent__) */
