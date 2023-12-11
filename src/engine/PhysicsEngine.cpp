//
// Created by micha on 30/11/2023.
//

#include "PhysicsEngine.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "SFML/Graphics/ConvexShape.hpp"

// Set the static variables
float PhysicsEngine::timeStep = 1.0f / 60.0f;
int32 PhysicsEngine::velocityIterations = 6;
int32 PhysicsEngine::positionIterations = 2;
float PhysicsEngine::physicsScale = 30.0f;
float PhysicsEngine::inversePhysicsScale = 1.0f / physicsScale;
float PhysicsEngine::total_frame_time = 0.0f;
bool PhysicsEngine::debugDrawEnabled = false;

void PhysicsEngine::Update(b2World *world, float deltaTime) {
    total_frame_time += deltaTime;
    while (total_frame_time >= timeStep) {
        world->Step(timeStep, velocityIterations, positionIterations);
        total_frame_time -= timeStep;
    }
}

shared_ptr<b2World> PhysicsEngine::CreateWorld() {
    auto world = make_shared<b2World>(b2Vec2(0.0f, 90.8f));
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

void PhysicsEngine::SetDebugDrawEnabled(bool enabled) {
    debugDrawEnabled = enabled;
}

void PhysicsEngine::RenderDebugData(b2World *world, RenderWindow *window) {
    if (debugDrawEnabled) {
        world->DrawDebugData();

        for (b2Body* body = world->GetBodyList(); body; body = body->GetNext()) {
            for (b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
                auto* polygonShape = (b2PolygonShape*)fixture->GetShape();

                sf::ConvexShape convexShape;
                convexShape.setPointCount(polygonShape->m_count);

                for (int i = 0; i < polygonShape->m_count; i++) {
                    b2Vec2 vertex = polygonShape->m_vertices[i];
                    sf::Vector2f sfmlVertex = PhysicsEngine::PhysicsToGraphics(vertex);
                    convexShape.setPoint(i, sfmlVertex);
                }

                convexShape.setFillColor(sf::Color(255, 0, 0, 50));
                convexShape.setOutlineThickness(1);
                convexShape.setOutlineColor(sf::Color::Red);

                convexShape.setPosition(PhysicsEngine::PhysicsToGraphics({body->GetPosition().x, body->GetPosition().y}));

                window->draw(convexShape);
            }
        }
    }
}




