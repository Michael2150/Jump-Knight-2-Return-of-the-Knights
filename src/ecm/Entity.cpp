//
// Created by micha on 26/11/2023.
//

#include "Entity.h"

using namespace std;

void Entity::Start() {
    for (const auto& component : components) {
        component->Start();
    }
}

void Entity::Update(float deltaTime) {
    for (const auto& component : components) {
        component->Update(deltaTime);
    }
}

void Entity::Render(sf::RenderWindow* window) {
    for (const auto& component : components) {
        component->Render(window);
    }
}

void Entity::AddComponent(const shared_ptr<Component>& component) {
    component->setParent(this);
    components.push_back(component);
}
