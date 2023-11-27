#include <iostream>
#include "engine/GameEngine.h"

GameEngine* engine = GameEngine::getInstance();

int main() {
    engine->Start(1280, 720, "CA3");
    return 0;
}
