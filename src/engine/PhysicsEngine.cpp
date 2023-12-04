//
// Created by micha on 30/11/2023.
//

#include "PhysicsEngine.h"

// Set the static variables
float PhysicsEngine::timeStep = 1.0f / 60.0f;
int32 PhysicsEngine::velocityIterations = 6;
int32 PhysicsEngine::positionIterations = 2;
float PhysicsEngine::physicsScale = 200.0f;
float PhysicsEngine::inversePhysicsScale = 1.0f / physicsScale;
float PhysicsEngine::total_frame_time = 0.0f;

void PhysicsEngine::Update(b2World *world, float deltaTime) {
    total_frame_time += deltaTime;
    while (total_frame_time >= timeStep) {
        world->Step(timeStep, velocityIterations, positionIterations);
        total_frame_time -= timeStep;
    }
}

shared_ptr<b2World> PhysicsEngine::CreateWorld() {
    auto world = make_shared<b2World>(b2Vec2(0.0f, 9.8f));
    world->SetAllowSleeping(true); // Allow objects that are at rest to fall asleep and be excluded from calculations
    world->SetContinuousPhysics(true); // Allow for continuous collision detection
    return world;
}

float PhysicsEngine::PhysicsToGraphics(float physicsValue) {
    return physicsValue * physicsScale;
}

float PhysicsEngine::GraphicsToPhysics(float graphicsValue) {
    return graphicsValue * inversePhysicsScale;
}

b2Vec2 PhysicsEngine::GraphicsToPhysics(const Vector2f &graphicsVector) {
    return {GraphicsToPhysics(graphicsVector.x), GraphicsToPhysics(graphicsVector.y)};
}

Vector2f PhysicsEngine::PhysicsToGraphics(const b2Vec2 &physicsVector) {
    return {PhysicsToGraphics(physicsVector.x), PhysicsToGraphics(physicsVector.y)};
}




