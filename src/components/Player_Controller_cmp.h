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
#include "Text_cmp.h"

class Player_Controller_cmp : public Component_Physics {

private:
    b2World* world;
    Player_Animator_cmp* animator{};
    Text_cmp* text {};
    float speed = 400.f;
    float jumpForce = 300.f;
    bool isJumping = false;

public:
    explicit Player_Controller_cmp(b2World* world) : world(world) {  }

    void Start() override {
        Component::Start();

        text = parent->getComponent<Text_cmp>().get();
        text->setOrigin({15.0f, 20.0f});
        text->setCharacterSize(12);

        auto playerSize = Vector2f(parent->getTransform()->getScale().x * 20.0f, parent->getTransform()->getScale().y * 30.0f);
        auto playerPhysicsSize = PhysicsEngine::GraphicsToPhysics(playerSize);

        // Create the player
        b2BodyDef playerBodyDef;
        playerBodyDef.type = b2_dynamicBody;
        playerBodyDef.bullet = true;
        playerBodyDef.fixedRotation = true;
        auto physicsPosition = PhysicsEngine::GraphicsToPhysics(parent->getTransform()->getPosition() );
        playerBodyDef.position.Set(physicsPosition.x, physicsPosition.y);
        this->body = world->CreateBody(&playerBodyDef);

        // Create the player fixture
        b2PolygonShape playerBox;
        playerBox.SetAsBox(playerPhysicsSize.x * 0.5f, playerPhysicsSize.y * 0.5f);
        b2FixtureDef playerFixtureDef;
        playerFixtureDef.shape = &playerBox;
        playerFixtureDef.density = 1.0f;
        playerFixtureDef.friction = 0.f;

        this->body->CreateFixture(&playerFixtureDef);

        animator = parent->getComponent<Player_Animator_cmp>().get();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        HandleInput();

        if (parent->getTransform()->hasPosChanged()) {
            auto physicsPosition = PhysicsEngine::GraphicsToPhysics(parent->getTransform()->getPosition());
            body->SetTransform(physicsPosition, body->GetAngle());
        }

        text->setText("Player Position: " + to_string(body->GetPosition().x) + ", " + to_string(body->GetPosition().y) + "\n" +
                      "Player Velocity: " + to_string(body->GetLinearVelocity().x) + ", " + to_string(body->GetLinearVelocity().y) + "\n");

        if (isJumping) {
            // if the player starts to fall
            if (body->GetLinearVelocity().y > 0.001f) {
                isJumping = false;
            }
        }

        parent->getTransform()->setPosition(PhysicsEngine::PhysicsToGraphics(body->GetPosition()));
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
            !isJumping &&
            body->GetLinearVelocity().y > -0.001f && body->GetLinearVelocity().y < 0.001f){
            body->ApplyLinearImpulse(b2Vec2(0, -jumpForce), body->GetWorldCenter(), true);

            isJumping = true;
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
