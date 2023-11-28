//
// Created by micha on 26/11/2023.
//

#ifndef CA3_GAMEENGINE_H
#define CA3_GAMEENGINE_H

#include "../ecm/Entity.h"
#include "Box2D/Dynamics/b2World.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GameEngine {
private:
    double physics_engine_steps_interval = 0.f; // Gets set in GameEngine::Initialize based on the desired FPS (e.g. 0.016 for 60 FPS)
    static GameEngine* instance;
    RenderWindow* window;
    vector<shared_ptr<Entity>> entities;
    b2World* world;

public:
    static GameEngine* getInstance();

    void Initialize(int width, int height, const std::string& title);
    void Start();

    b2World& getWorld() { return *world; }
    RenderWindow& getWindow() { return *window; }
    Vector2i getScreenSize() { return {static_cast<int>(window->getSize().x), static_cast<int>(window->getSize().y)}; }
};

#endif //CA3_GAMEENGINE_H
