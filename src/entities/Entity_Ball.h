//
// Created by micha on 30/11/2023.
//

#ifndef CA3_ENTITY_BALL_H
#define CA3_ENTITY_BALL_H

#include <iostream>
#include "../ecm/Entity.h"
#include "Box2D/Dynamics/b2World.h"
#include "SFML/Graphics/Shape.hpp"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "../engine/GameEngine.h"
#include "Component_PhysicsShapeRenderer.h"

class Component_BallPhysics : public Component_Physics {
private:
    b2World* world;

public:
    explicit Component_BallPhysics(Entity* parent, b2World* world) : world(world) {
        this->parent = parent;

        // Create the ball
        b2BodyDef ballBodyDef;
        ballBodyDef.type = b2_dynamicBody;
        ballBodyDef.position.Set(parent->getTransform().getPosition().x, parent->getTransform().getPosition().y);
        this->body = world->CreateBody(&ballBodyDef);

        // Create the ball fixture
        b2CircleShape ballCircle;
        ballCircle.m_radius = 20.0f;
        b2FixtureDef ballFixtureDef;
        ballFixtureDef.shape = &ballCircle;
        ballFixtureDef.density = 1.0f;
        ballFixtureDef.friction = 0.3f;
        this->body->CreateFixture(&ballFixtureDef);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        parent->getTransform().setPosition({this->body->GetPosition().x, this->body->GetPosition().y});
    }
};


class Entity_Ball : public Entity {
private:
    b2World* world;
    sf::CircleShape* shape{};
public:
    explicit Entity_Ball(b2World* world) : world(world) { }

    void Start() override {
        auto GameSize = GameEngine::getInstance()->getScreenSize();

        transform.setPosition({static_cast<float>(GameSize.x / 2),
                               static_cast<float>(GameSize.y / 2)});

        auto physics = CreateComponent<Component_BallPhysics>(this, world);
        shape = new sf::CircleShape(20.0f);
        shape->setOrigin(20.0f, 20.0f);
        shape->setFillColor(sf::Color::Red);
        auto renderer = CreateComponent<Component_PhysicsShapeRenderer>(physics.get(), shape);

        Entity::Start();
    }
};


#endif //CA3_ENTITY_BALL_H
