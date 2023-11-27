//
// Created by micha on 27/11/2023.
//

#ifndef CA3_COMP_BALL_H
#define CA3_COMP_BALL_H

#include "Component.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Box2D/Collision/Shapes/b2CircleShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include <SFML/Graphics.hpp>

class comp_ball : public Component{
public:
    b2Body* body;

    comp_ball(float x, float y, float radius) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(x, y);

        body = GameEngine::getInstance()->getWorld().CreateBody(&bodyDef);

        b2CircleShape ballShape;
        ballShape.m_radius = radius;

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &ballShape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;

        body->CreateFixture(&fixtureDef);
    }

    void Start() override {
        Component::Start();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
    }

    void Render() override {
        Component::Render();
    }
};


#endif //CA3_COMP_BALL_H
