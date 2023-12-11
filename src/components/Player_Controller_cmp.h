//
// Created by ugwul on 09/12/2023.
//

#ifndef CA3_PLAYER_CONTROLLER_CMP_H
#define CA3_PLAYER_CONTROLLER_CMP_H

#include "../ecm/Component.h"
#include "../engine/GameEngine.h"
#include "Box2D/Dynamics/b2Body.h"
#include "Component_Physics.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"
#include "Player_Animator_cmp.h"

class Player_Controller_cmp : public Component_Physics {

private:
    b2World* world;
    Player_Animator_cmp* animator{};
    float speed = 300.0f;

public:
    explicit Player_Controller_cmp(b2World* world) : world(world) {  }

    void Start() override {
        Component::Start();

        auto playerSize = Vector2f(parent->getTransform().getScale().x * 27.0f, parent->getTransform().getScale().y * 40.0f);
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

        animator = parent->getComponent<Player_Animator_cmp>().get();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        HandleInput();

        parent->getTransform().setPosition(PhysicsEngine::PhysicsToGraphics(body->GetPosition()));
    }

    void HandleInput(){
        auto velocity = body->GetLinearVelocity();


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            velocity.x = PhysicsEngine::GraphicsToPhysics(-speed);
            animator->SetAnimation(Player_Animator_cmp::animation_state::run);
            animator->setFlip(true);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x = PhysicsEngine::GraphicsToPhysics(speed);
            animator->SetAnimation(Player_Animator_cmp::animation_state::run);
            animator->setFlip(false);
        } else {
            velocity.x = 0.0f;
            animator->SetAnimation(Player_Animator_cmp::animation_state::idle);
        }

        body->SetLinearVelocity(velocity);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
            body->GetLinearVelocity().y > -0.001f && body->GetLinearVelocity().y < 0.001f){
            auto jumpForce = PhysicsEngine::GraphicsToPhysics(Vector2f(0.0f, -parent->getTransform().getScale().y * 50.0f));
            body->ApplyLinearImpulse(jumpForce, body->GetWorldCenter(), true);
        }

        if(body->GetLinearVelocity().y > 0.001f){
            animator->SetAnimation(Player_Animator_cmp::animation_state::fall);
        }

        if(body->GetLinearVelocity().y < -0.001f){
            animator->SetAnimation(Player_Animator_cmp::animation_state::jump);
        }
    }

};

#endif //CA3_PLAYER_CONTROLLER_CMP_H
