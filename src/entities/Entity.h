//
// Created by micha on 26/11/2023.
//

#ifndef CA3_ENTITY_H
#define CA3_ENTITY_H

#include "vector"
#include "../components/Component.h"
#include "SFML/System/Vector2.hpp"
#include <memory>
#include <string>

class Entity {
private:
    std::vector<std::shared_ptr<Component>> components;

public:
    sf::Vector2f position;
    sf::Vector2f scale;
    float rotation;

    void Start();
    void Update(float deltaTime);
    void Render();

    void AddComponent(std::shared_ptr<Component> component);
    std::vector<std::shared_ptr<Component>> GetComponents();
};


#endif //CA3_ENTITY_H
