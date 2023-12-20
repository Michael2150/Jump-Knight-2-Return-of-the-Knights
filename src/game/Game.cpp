#include "Game.h"
#include "../components/hello_world_component.h"
#include "../components/Text_cmp.h"

// Menu Scene
void MenuScene::Initialize() {
//    PhysicsEngine::SetDebugDrawEnabled(true);

    auto Title = CreateEntity<Entity>();
    auto TitleText = Title->CreateComponent<Text_cmp>("Jump Knight");
    TitleText->setCharacterSize(100);
    TitleText->setFillColor(sf::Color::White);
    Title->getTransform()->setPosition({400, 100});
}
void MenuScene::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        RespawnPlayer();
        GameEngine::getInstance()->PlaySound("resources/Music/Menu_Music.ogg");
    } else {
        RespawnPlayer();
    }
}

// Level 1
void Level1::Initialize() {
    // Other Entities can be set up here:
}
void Level1::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        RespawnPlayer();
        GameEngine::getInstance()->PlaySound("resources/Music/Level_1_Music.ogg");
    } else {
        RespawnPlayer();
    }
}

// Level 2
void Level2::Initialize() {
    // Other Entities can be set up here:
}
void Level2::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        RespawnPlayer();
        GameEngine::getInstance()->PlaySound("resources/Music/Level_2_Music.ogg");
    } else {
        RespawnPlayer();
    }
}

// End Scene
void EndScene::Initialize() {
    // Other Entities can be set up here:
}
void EndScene::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        RespawnPlayer();
        GameEngine::getInstance()->PlaySound("resources/Music/Level_2_Music.ogg");
    } else {
        RespawnPlayer();
    }
}
