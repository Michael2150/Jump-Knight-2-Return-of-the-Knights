//
// Created by micha on 26/11/2023.
//

#include <iostream>
#include "GameEngine.h"

GameEngine* GameEngine::instance = nullptr;

GameEngine::GameEngine() {
    std::cout << "GameEngine created" << std::endl;
}

GameEngine *GameEngine::getInstance() {
    if (instance == nullptr) {
        instance = new GameEngine();
    }
    return instance;
}
