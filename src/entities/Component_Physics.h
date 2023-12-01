//
// Created by micha on 01/12/2023.
//

#ifndef CA3_COMPONENT_PHYSICS_H
#define CA3_COMPONENT_PHYSICS_H

#include "Box2D/Dynamics/b2Body.h"
#include "../ecm/Component.h"

// interface that always has a getBody() method
class Component_Physics : public Component {
protected:
    b2Body* body = nullptr;
public:
    b2Body* getBody() {
        return body;
    }
};

#endif //CA3_COMPONENT_PHYSICS_H
