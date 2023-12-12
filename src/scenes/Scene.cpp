//
// Created by micha on 30/11/2023.
//

#include "Scene.h"
#include "../engine/GameEngine.h"
#include "../entities/Player_Entity.h"

Scene::Scene(const string& LevelMapPath, bool requiresPlayer) {
    entities = vector<shared_ptr<Entity>>();
    world = PhysicsEngine::CreateWorld();

    auto screenSize = GameEngine::getInstance()->getScreenSize();
    viewport = View(FloatRect(0, 0, screenSize.x, screenSize.y));

    this->levelMap = CreateEntity<LevelMap>(LevelMapPath, GameEngine::sourceTileSet);
    this->levelMap->getLayer("platforms")->setTileSetAsStaticBody(this->getWorld());
    this->levelMap->getLayer("special")->shouldRender = false;

    if (requiresPlayer) {
        this->player = CreateEntity<Player_Entity>(this->getWorld());
    }
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

void Scene::setActive(bool isActive) {
    if (isActive) {
        GameEngine::getInstance()->getWindow().setView(viewport);
    }
}

void Scene::RespawnPlayer() {
    auto specialLayer = this->levelMap->getLayer("special");
    auto spawnPos = specialLayer->getTilePosition(static_cast<int>(SpecialTile::SPAWN));
    this->player->getTransform()->setPosition(spawnPos);
    this->player->getTransform()->PositionChanged();
}


