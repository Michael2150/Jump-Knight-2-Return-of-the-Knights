#include "Game.h"
#include "../entities/Component_Text.h"
#include "../entities/Entity_Ball.h"
#include "../entities/hello_world_component.h"

void MenuScene::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Menu Scene");

    for (int i = 0; i < 10; i++) {
        auto Ball = CreateEntity<Entity_Ball>(this->getWorld());
    }
}

void Level1::Initialize() {
    auto TitleText = CreateEntity<Entity>();
    auto textComponent = TitleText->CreateComponent<Component_Text>("Level 1");

    auto hello = CreateEntity<Entity>();
    hello->CreateComponent<hello_world_component>(this->getWorld());
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
