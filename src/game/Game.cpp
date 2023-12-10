#include "Game.h"
#include "../entities/Component_Text.h"
#include "../entities/hello_world_component.h"
#include "../level_system/LevelMap.h"
#include "../entities/PlayerController.h"
#include "../level_system/TileSet.h"

void MenuScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Menu Scene");

    auto tileset = CreateEntity<TileSet>("resources/environment/tileset.png", sf::Vector2u(8, 8), sf::Vector2u(8, 12));
    tileset->shouldRender = false;
    auto levelMap = CreateEntity<LevelMap>("resources/tiled/level_1_map.json", *tileset);
}

void Level1::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Level 1");

    auto hello = CreateEntity<Entity>();
    hello->CreateComponent<hello_world_component>(this->getWorld());

    // Create the player and set its position
    auto player = CreateEntity<Entity>();
    player->getTransform().setPosition({100.0f, 100.0f});

    auto cntrl = player->CreateComponent<PlayerController>(this->getWorld());
}

void Level2::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Level 2");
}

void Level3::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Level 3");
}

void EndScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("End Scene");
}
