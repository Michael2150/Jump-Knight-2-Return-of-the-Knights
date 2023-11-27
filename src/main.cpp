#include <iostream>
#include "engine/GameEngine.h"

GameEngine* engine = GameEngine::getInstance();

int main() {
    engine->Initialize(1280, 720, "CA3");
    engine->Start();
    return 0;
}
