//
// Created by ugwul on 09/12/2023.
//

#ifndef CA3_PLAYERCONTROLLER_H
#define CA3_PLAYERCONTROLLER_H

#include "../ecm/Component.h"
#include "../engine/GameEngine.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Component_Physics.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"

class PlayerController : public Component_Physics {

private:
    b2World* world;

public:
    explicit PlayerController(b2World* world) : world(world) {  }

    void Start() override {
        Component::Start();

        auto playerSize = Vector2f(50.0f, 50.0f);
        auto playerPhysicsSize = PhysicsEngine::GraphicsToPhysics(playerSize);

        // Create the player
        b2BodyDef playerBodyDef;
        playerBodyDef.type = b2_dynamicBody;
        auto physicsPosition = PhysicsEngine::GraphicsToPhysics(parent->getTransform().getPosition());
        playerBodyDef.position.Set(physicsPosition.x, physicsPosition.y);
        this->body = world->CreateBody(&playerBodyDef);

        // Create the player fixture
        b2PolygonShape playerBox;
        playerBox.SetAsBox(playerPhysicsSize.x * 0.5f, playerPhysicsSize.y * 0.5f);
        b2FixtureDef playerFixtureDef;
        playerFixtureDef.shape = &playerBox;
        playerFixtureDef.density = 1.0f;
        playerFixtureDef.friction = 1.f;
        this->body->CreateFixture(&playerFixtureDef);

    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        HandleInput();

        parent->getTransform().setPosition(PhysicsEngine::PhysicsToGraphics(body->GetPosition()));
    }

    void HandleInput(){
        auto velocity = body->GetLinearVelocity();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            velocity.x = PhysicsEngine::GraphicsToPhysics(-150.0f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x = PhysicsEngine::GraphicsToPhysics(150.0f);
        } else {
            velocity.x = 0.0f;
        }

        body->SetLinearVelocity(velocity);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
            body->GetLinearVelocity().y > -0.001f && body->GetLinearVelocity().y < 0.001f){
            auto jumpForce = PhysicsEngine::GraphicsToPhysics(Vector2f(0.0f, -50.0f));
            body->ApplyLinearImpulse(jumpForce, body->GetWorldCenter(), true);
        }
    }

};

#endif //CA3_PLAYERCONTROLLER_H
