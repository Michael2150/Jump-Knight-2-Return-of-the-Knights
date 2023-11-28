//
// Created by micha on 26/11/2023.
//

#ifndef CA3_COMPONENT_H
#define CA3_COMPONENT_H

#include "Component.h"
#include "../entities/Entity.h"

class Entity; // Forward declaration

class Component {
protected:
    bool isEnabled = true;
    Entity* parent;

public:
    explicit Component() : parent(nullptr) {}
    virtual void Start() {};
    virtual void Update(float deltaTime) {};
    virtual void Render() {};
};


#endif //CA3_COMPONENT_H
