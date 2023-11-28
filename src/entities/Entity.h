//
// Created by micha on 26/11/2023.
//

#ifndef CA3_ENTITY_H
#define CA3_ENTITY_H

#include "vector"
#include <memory>
#include <string>
#include "SFML/System/Vector2.hpp"

#include "Entity.h"
#include "../components/Component.h"
#include "../components/Transform.h"

class Component; // Forward declaration

class Entity {
private:
    Transform_Component transform;
    std::vector<Component*> components;

public:
    void Start();
    void Update(float deltaTime);
    void Render();

    void AddComponent(Component& component);
    std::vector<Component*> getComponents() { return components; }

    Transform_Component& getTransform() { return transform; }
};


#endif //CA3_ENTITY_H
