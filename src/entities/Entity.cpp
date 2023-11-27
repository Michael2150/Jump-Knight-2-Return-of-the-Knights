//
// Created by micha on 26/11/2023.
//

#include "Entity.h"

void Entity::Start() {
    for (auto &component : components) {
        component->Start();
    }

    for (auto &child : children) {
        child->Start();
    }
}

void Entity::Update(float deltaTime) {
    for (auto &component : components) {
        component->Update(deltaTime);
    }

    for (auto &child : children) {
        child->Update(deltaTime);
    }
}

void Entity::Render() {
    for (auto &component : components) {
        component->Render();
    }

    for (auto &child : children) {
        child->Render();
    }
}

void Entity::AddComponent(std::shared_ptr<Component> component) {
    components.push_back(component);
}

void Entity::AddChild(std::shared_ptr<Entity> child) {
    children.push_back(child);
}

std::vector<std::shared_ptr<Component>> Entity::GetComponents() {
    return components;
}

std::vector<std::shared_ptr<Entity>> Entity::GetChildren() {
    return children;
}
