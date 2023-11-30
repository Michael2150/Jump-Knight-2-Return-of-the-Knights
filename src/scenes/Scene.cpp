//
// Created by micha on 30/11/2023.
//

#include "Scene.h"

Scene::Scene() {
    world = new b2World(b2Vec2(0.f, 9.8f));
    entities = vector<shared_ptr<Entity>>();
}

void Scene::Start() {
    for (const auto& entity : entities) {
        entity->Start();
    }

    Entity::Start();

    b_started = true;
}

void Scene::Update(float deltaTime) {
    for (const auto& entity : entities) {
        entity->Update(deltaTime);
    }

    Entity::Update(deltaTime);
}

void Scene::Render(sf::RenderWindow *window) {
    for (const auto& entity : entities) {
        entity->Render(window);
    }

    Entity::Render(window);
}
