#include "Game.h"
#include "../components/Text_cmp.h"
#include "../components/hello_world_component.h"
#include "../level_system/LevelMap.h"
#include "../entities/Player_Entity.h"

void MenuScene::Initialize() {
    PhysicsEngine::SetDebugDrawEnabled(true);

    auto levelMap = CreateEntity<LevelMap>("resources/tiled/main_menu.json", GameEngine::sourceTileSet);
    levelMap->getLayer("platforms")->setTileSetAsStaticBody(this->getWorld());

    auto player = CreateEntity<Player_Entity>(this->getWorld());
    player->getTransform().setPosition({600.0f, 100.0f});
}

void Level1::Initialize() {
    auto levelMap = CreateEntity<LevelMap>("resources/tiled/level_1_map.json", GameEngine::sourceTileSet);
    levelMap->getLayer("platforms")->setTileSetAsStaticBody(this->getWorld());

    auto player = CreateEntity<Player_Entity>(this->getWorld());
    player->getTransform().setPosition({100.0f, 100.0f});
}

void Level2::Initialize() {
    auto levelMap = CreateEntity<LevelMap>("resources/tiled/level_2_map.json", GameEngine::sourceTileSet);
    levelMap->getLayer("platforms")->setTileSetAsStaticBody(this->getWorld());

    auto player = CreateEntity<Player_Entity>(this->getWorld());
    player->getTransform().setPosition({100.0f, 100.0f});
}

void Level3::Initialize() {
    auto levelMap = CreateEntity<LevelMap>("resources/tiled/level_3_map.json", GameEngine::sourceTileSet);
    levelMap->getLayer("platforms")->setTileSetAsStaticBody(this->getWorld());

    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("Level 3");
}

void EndScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("End Scene");
}
