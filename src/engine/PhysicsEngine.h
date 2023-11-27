//
// Created by micha on 27/11/2023.
//

#include "SFML/Graphics/RenderWindow.hpp"
#include "../entities/Entity.h"
#include <Box2D/Box2D.h>

class PhysicsEngine {
private:
    explicit PhysicsEngine(b2World &world) : world(world) {};
    b2World& world;
    static PhysicsEngine* instance;
public:
    b2World& getWorld() { return world; }
    static PhysicsEngine* getInstance();
};
