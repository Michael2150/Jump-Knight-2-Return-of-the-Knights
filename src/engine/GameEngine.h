//
// Created by micha on 26/11/2023.
//

#ifndef CA3_GAMEENGINE_H
#define CA3_GAMEENGINE_H

#include "../entities/Entity.h"
#include <SFML/Graphics.hpp>

class GameEngine {
private:
    GameEngine();
    sf::RenderWindow* window {};
    std::vector<std::shared_ptr<Entity>> entities;
    static GameEngine* instance;

public:
    GameEngine(GameEngine const&) = delete;
    void Start(int width, int height, std::string title);
    static GameEngine* getInstance();
    sf::Vector2<float> getScreenSize();
};

#endif //CA3_GAMEENGINE_H
