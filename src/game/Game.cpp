#include "Game.h"
#include "../components/Text_cmp.h"
#include "../components/hello_world_component.h"
#include "../level_system/LevelMap.h"
#include "../components/Player_Controller_cmp.h"
#include "../entities/Player_Entity.h"

void MenuScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("Menu Scene");

    auto source = GameEngine::sourceTileSet;
    auto levelMap = CreateEntity<LevelMap>("resources/tiled/level_1_map.json", source);
    levelMap->getLayer("platforms").setTileSetAsStaticBody(this->getWorld());

    auto player = CreateEntity<Player_Entity>(this->getWorld());
    player->getTransform().setPosition({100.0f, 100.0f});
}

void Level1::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("Level 1");

    auto hello = CreateEntity<Entity>();
    hello->CreateComponent<hello_world_component>(this->getWorld());

    auto player = CreateEntity<Player_Entity>(this->getWorld());
    player->getTransform().setPosition({100.0f, 100.0f});
}

void Level2::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("Level 2");
}

void Level3::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("Level 3");
}

void EndScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Text_cmp>("End Scene");
}
