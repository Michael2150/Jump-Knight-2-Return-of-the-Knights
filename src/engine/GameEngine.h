//
// Created by micha on 26/11/2023.
//

#ifndef CA3_GAMEENGINE_H
#define CA3_GAMEENGINE_H

#include "../entities/Entity.h"

class GameEngine : public Entity {
private:
    static GameEngine* instance;
public:
    GameEngine();
    GameEngine(GameEngine const&) = delete;
    static GameEngine* getInstance();
};


#endif //CA3_GAMEENGINE_H
