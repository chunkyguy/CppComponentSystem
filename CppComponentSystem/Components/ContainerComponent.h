//
//  HS_ContainerComponent.h
//  HitSoccer
//
//  Created by Sid on 21/07/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __HitSoccer__HS_ContainerComponent__
#define __HitSoccer__HS_ContainerComponent__
#include <utility>
#include <vector>

/** Adds functionality to add/remove and manage child game objects */
template <typename... Component>
class ContainerComponent {
protected:
    std::tuple<std::vector<Component*>...> children_;
};

#endif /* defined(__HitSoccer__HS_ContainerComponent__) */
