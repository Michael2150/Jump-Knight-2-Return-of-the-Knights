#include "Game.h"
#include "../entities/Component_Text.h"
#include "../entities/hello_world_component.h"
#include "../level_system/LevelMap.h"
#include "../level_system/Tileset.h"
#include "../entities/PlayerController.h"
#include "../entities/Animation_cmp.h"
#include "../entities/Animator_Player_cmp.h"

void MenuScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Menu Scene");

    auto tileset = std::make_shared<Tileset>("resources/environment/tileset.png");

    auto Level = LevelMap("resources/tiled/level_1_map.json");
}

void Level1::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Level 1");

    auto hello = CreateEntity<Entity>();
    hello->CreateComponent<hello_world_component>(this->getWorld());

    // Create the player and set its position
    auto player = CreateEntity<Entity>();
    player->CreateComponent<PlayerController>(this->getWorld());
    player->CreateComponent<Animator_Player_cmp>();
    player->getTransform().setScale({2.0f, 2.0f});


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
