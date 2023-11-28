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
#include "Component.h"
#include "Transform.h"
#include "SFML/Graphics/RenderWindow.hpp"

class Component; // Forward declaration

using namespace std;

class Entity {
private:
    Transform_Component transform;
    vector<shared_ptr<Component>> components;

public:
    explicit Entity() : transform(Transform_Component()) {
        components = vector<shared_ptr<Component>>();
    };

    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void Render(sf::RenderWindow* window);

    void AddComponent(const shared_ptr<Component>& component);
    std::vector<shared_ptr<Component>> getComponents() { return components; }

    Transform_Component& getTransform() { return transform; }
};


#endif //CA3_ENTITY_H
