#include "Game.h"
#include "../components/hello_world_component.h"
#include "../components/Text_cmp.h"

// Menu Scene
void MenuScene::Initialize() {
//    PhysicsEngine::SetDebugDrawEnabled(true);
    // Get the special layer
    auto specialLayer = this->levelMap->getLayer("special");
    auto TitlePos = specialLayer->getTilePosition(static_cast<int>(SpecialTile::TEXT_POSITION));
    auto Title = CreateEntity<Entity>();
    Title->getTransform()->setPosition(TitlePos);
    auto TitleText = Title->CreateComponent<Text_cmp>("Jump Knight \n\n  [A] or [D] to move \n  [Space] to jump ", 35, sf::Color::White, "resources/fonts/marker.ttf");
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
    // Get the special layer
    auto specialLayer = this->levelMap->getLayer("special");
    auto TitlePos = specialLayer->getTilePosition(static_cast<int>(SpecialTile::TEXT_POSITION));
    auto Title = CreateEntity<Entity>();
    Title->getTransform()->setPosition(TitlePos);
    auto TitleText = Title->CreateComponent<Text_cmp>("You made it!, go through the door to restart", 35, sf::Color::White, "resources/fonts/marker.ttf");
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
