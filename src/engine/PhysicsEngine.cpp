//
// Created by micha on 30/11/2023.
//

#include "PhysicsEngine.h"

// Set the static variables
float PhysicsEngine::timeStep = 1.0f / 60.0f;
int32 PhysicsEngine::velocityIterations = 6;
int32 PhysicsEngine::positionIterations = 2;

void PhysicsEngine::Update(b2World *world) {
    world->Step(timeStep, velocityIterations, positionIterations);
}

shared_ptr<b2World> PhysicsEngine::CreateWorld() {
    auto world = make_shared<b2World>(b2Vec2(0.0f, 9.8f));
    world->SetAllowSleeping(true); // Allow objects that are at rest to fall asleep and be excluded from calculations
    world->SetContinuousPhysics(true); // Allow for continuous collision detection
    return world;
}
