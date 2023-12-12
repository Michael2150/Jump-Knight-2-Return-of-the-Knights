#include "Game.h"
#include "../components/hello_world_component.h"

// Menu Scene
void MenuScene::Initialize() {
    PhysicsEngine::SetDebugDrawEnabled(true);
}
void MenuScene::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        GameEngine::getInstance()->PlaySound("resources/Music/Menu_Music.ogg");
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
    }
}

// Level 3
void Level3::Initialize() {
    // Other Entities can be set up here:
}
void Level3::setActive(bool isActive) {
    Scene::setActive(isActive);
    if (isActive) {
        RespawnPlayer();
        GameEngine::getInstance()->PlaySound("resources/Music/Level_3_Music.ogg");
    }
}

// End Scene
void EndScene::Initialize() {
    // Other Entities can be set up here:
}
void EndScene::setActive(bool isActive) {
    Scene::setActive(isActive);
}
