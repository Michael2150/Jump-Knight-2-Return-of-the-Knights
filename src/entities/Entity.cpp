//
// Created by micha on 26/11/2023.
//

#include "Entity.h"

void Entity::Start() {
    for (auto &component : components) {
        component->Start();
    }
}

void Entity::Update(float deltaTime) {
    for (auto &component : components) {
        component->Update(deltaTime);
    }
}

void Entity::Render() {
    for (auto &component : components) {
        component->Render();
    }
}

void Entity::AddComponent(std::shared_ptr<Component> component) {
    components.push_back(component);
}

std::vector<std::shared_ptr<Component>> Entity::GetComponents() {
    return components;
}
