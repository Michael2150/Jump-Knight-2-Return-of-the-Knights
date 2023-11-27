#ifndef CA3_PHYSICSENGINE_H
#define CA3_PHYSICSENGINE_H

#include "PhysicsEngine.h"

PhysicsEngine *PhysicsEngine::instance = nullptr;

PhysicsEngine *PhysicsEngine::getInstance() {
    if (instance == nullptr) {
        auto gravity = b2Vec2(0.0f, 9.8f);
        auto world = b2World(gravity);
        instance = new PhysicsEngine(world);
    }
    return instance;
}

#endif //CA3_PHYSICSENGINE_H