//
// Created by micha on 30/11/2023.
//

#ifndef CA3_HELLO_WORLD_COMPONENT_H
#define CA3_HELLO_WORLD_COMPONENT_H

#include "../ecm/Component.h"
#include "Box2D/Dynamics/b2World.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "SFML/Graphics/RectangleShape.hpp"

class hello_world_component : public Component {
private:
    b2World* world;
    b2Body* ballBody;
    sf::CircleShape ballShape;
    sf::RectangleShape* groundShape;

public:
    explicit hello_world_component(b2World* world) : world(world) {}

    void Start() override {
        Component::Start();

        // Create the ground
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(400.0f, 500.0f);
        b2Body* groundBody = world->CreateBody(&groundBodyDef);

        // Create the ground fixture
        b2PolygonShape groundBox;
        groundBox.SetAsBox(400.0f, 10.0f);
        groundBody->CreateFixture(&groundBox, 0.0f);

        // Ground shape
        groundShape = new sf::RectangleShape(sf::Vector2f(800.0f, 20.0f));
        groundShape->setPosition(groundBody->GetPosition().x, groundBody->GetPosition().y);
        groundShape->setFillColor(sf::Color::Green);

        // Create the ball
        b2BodyDef ballBodyDef;
        ballBodyDef.type = b2_dynamicBody;
        ballBodyDef.position.Set(400.0f, 100.0f);
        ballBody = world->CreateBody(&ballBodyDef);

        // Create the ball fixture
        b2CircleShape ballCircle;
        ballCircle.m_radius = 20.0f;
        b2FixtureDef ballFixtureDef;
        ballFixtureDef.shape = &ballCircle;
        ballFixtureDef.density = 1.0f;
        ballFixtureDef.friction = 0.3f;
        ballBody->CreateFixture(&ballFixtureDef);

        // Create the ball shape
        ballShape.setRadius(20.0f);
        ballShape.setFillColor(sf::Color::Red);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        ballShape.setPosition(ballBody->GetPosition().x, ballBody->GetPosition().y);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        window->draw(ballShape);
        window->draw(*groundShape);
    }
};

#endif //CA3_HELLO_WORLD_COMPONENT_H
