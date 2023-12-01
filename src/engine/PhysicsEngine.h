//
// Created by micha on 30/11/2023.
//

#ifndef CA3_PHYSICSENGINE_H
#define CA3_PHYSICSENGINE_H


#include <memory>
#include "Box2D/Common/b2Settings.h"
#include "Box2D/Dynamics/b2World.h"

using namespace std;

class PhysicsEngine {
private:
    static int32 velocityIterations;
    static int32 positionIterations;
    static float timeStep;

public:
    PhysicsEngine() = default;
    static void Update(b2World* world);
    static shared_ptr<b2World> CreateWorld();
};


#endif //CA3_PHYSICSENGINE_H
