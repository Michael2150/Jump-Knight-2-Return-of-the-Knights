//
// Created by micha on 30/11/2023.
//

#include "Scene.h"

Scene::Scene() {
    entities = vector<shared_ptr<Entity>>();
    world = PhysicsEngine::CreateWorld();
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

    PhysicsEngine::Update(world.get(), deltaTime);

    Entity::Update(deltaTime);
}

void Scene::Render(sf::RenderWindow *window) {
    for (const auto& entity : entities) {
        entity->Render(window);
    }

    Entity::Render(window);

    PhysicsEngine::RenderDebugData(world.get(), window);
}