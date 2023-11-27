//
// Created by micha on 26/11/2023.
//

#ifndef CA3_ENTITY_H
#define CA3_ENTITY_H

#include "vector"
#include "../components/Component.h"
#include <memory>
#include <string>

class Entity {
private:
    std::vector<std::shared_ptr<Component>> components;
    std::vector<std::shared_ptr<Entity>> children;

public:
    void Start();
    void Update(float deltaTime);
    void Render();

    void AddComponent(std::shared_ptr<Component> component);
    void AddChild(std::shared_ptr<Entity> child);

    std::vector<std::shared_ptr<Component>> GetComponents();
    std::vector<std::shared_ptr<Entity>> GetChildren();
};


#endif //CA3_ENTITY_H
