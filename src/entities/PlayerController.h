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
#include "Component_PhysicsShapeRenderer.h"

class PlayerController : public Component_Physics {

private:
    b2World* world;
    Vector2f velocity = {0.0f, 0.0f};
    Vector2f acceleration = {0.0f, 0.f};
    sf::RectangleShape playerShape;
public:


public:
    explicit PlayerController(b2World* world) : world(world) {  }

    void Start() override {
        Component::Start();

        auto screenSize = GameEngine::getInstance()->getScreenSize();

        // Create the player
        b2BodyDef playerBodyDef;
        playerBodyDef.type = b2_dynamicBody;
        auto playerPosition = Vector2f(screenSize.x * 0.6f, screenSize.y * 0.3f);
        auto physicsPosition = PhysicsEngine::GraphicsToPhysics(playerPosition);
        playerBodyDef.position.Set(physicsPosition.x, physicsPosition.y);
        this->body = world->CreateBody(&playerBodyDef);

        // Create the player fixture
        b2PolygonShape playerBox;
        auto playerSize = Vector2f(50.0f, 50.0f);
        playerBox.SetAsBox(PhysicsEngine::GraphicsToPhysics(playerSize.x), PhysicsEngine::GraphicsToPhysics(playerSize.y));
        b2FixtureDef playerFixtureDef;
        playerFixtureDef.shape = &playerBox;
        playerFixtureDef.density = 1.0f;
        playerFixtureDef.friction = 0.3f;
        this->body->CreateFixture(&playerFixtureDef);

        // Create the player shape
        playerShape = sf::RectangleShape(playerSize);
        playerShape.setOrigin(playerSize * 0.5f);
        playerShape.setFillColor(sf::Color::Blue);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        window->draw(playerShape);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        HandleInput();

        playerShape.setPosition(PhysicsEngine::PhysicsToGraphics(body->GetPosition()));
        playerShape.setRotation(body->GetAngle() * 180.0f / b2_pi);

    }

    void HandleInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        acceleration.x = -10.0f;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        acceleration.x = 10.0f;
    } else {
        acceleration.x = 0.0f;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && body->GetLinearVelocity().y == 0){
        body->ApplyLinearImpulseToCenter(b2Vec2(0.0, -100.0f), true);
    }
}

};

#endif //CA3_PLAYERCONTROLLER_H
