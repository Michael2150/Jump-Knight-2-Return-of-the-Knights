//
// Created by micha on 30/11/2023.
//

#ifndef CA3_PHYSICSENGINE_H
#define CA3_PHYSICSENGINE_H


#include <memory>
#include "Box2D/Common/b2Settings.h"
#include "Box2D/Dynamics/b2World.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

using namespace std;
using namespace sf;

class PhysicsEngine {
private:
    static int32 velocityIterations;
    static int32 positionIterations;
    static float physicsScale;
    static float inversePhysicsScale;
    static float timeStep;
    static float total_frame_time;
    static bool debugDrawEnabled;

public:
    PhysicsEngine() = default;
    static void Update(b2World* world, float deltaTime);
    static void SetDebugDrawEnabled(bool enabled);
    static void RenderDebugData(b2World* world, RenderWindow* window);
    static shared_ptr<b2World> CreateWorld();
    static Vector2f PhysicsToGraphics(const b2Vec2& physicsVector);
    static b2Vec2 GraphicsToPhysics(const Vector2f& graphicsVector);
    static float PhysicsToGraphics(float physicsValue);
    static float GraphicsToPhysics(float graphicsValue);
};


#endif //CA3_PHYSICSENGINE_H
