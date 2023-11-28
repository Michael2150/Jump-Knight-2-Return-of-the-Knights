//
// Created by micha on 26/11/2023.
//

#ifndef CA3_COMPONENT_H
#define CA3_COMPONENT_H

#include "Component.h"
#include "Entity.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Entity; // Forward declaration

using namespace std;

class Component {
protected:
    bool isEnabled = true;
    Entity* parent;

public:
    explicit Component() : parent(nullptr) {};
    virtual void Start() {};
    virtual void Update(float deltaTime) {};
    virtual void Render(sf::RenderWindow* window) {};
    void setParent(Entity* parent) { this->parent = parent; }
};


#endif //CA3_COMPONENT_H
