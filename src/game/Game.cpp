#include "Game.h"
#include "../components/text_component.h"

void MenuScene::Initialize() {
    auto GameName = CreateEntity<Entity>();
    auto Text = make_shared<TextComponent>();
    Text->setText("Menu Scene");
    GameName->AddComponent(Text);
}

void Level1::Initialize() {
    auto GameName = CreateEntity<Entity>();
    auto Text = make_shared<TextComponent>();
    Text->setText("Level 1");
    GameName->AddComponent(Text);
}

void Level2::Initialize() {
    auto GameName = CreateEntity<Entity>();
    auto Text = make_shared<TextComponent>();
    Text->setText("Level 2");
    GameName->AddComponent(Text);
}

void Level3::Initialize() {
    auto GameName = CreateEntity<Entity>();
    auto Text = make_shared<TextComponent>();
    Text->setText("Level 3");
    GameName->AddComponent(Text);
}

void EndScene::Initialize() {
    auto GameName = CreateEntity<Entity>();
    auto Text = make_shared<TextComponent>();
    Text->setText("End Scene");
    GameName->AddComponent(Text);
}
