//
// Created by micha on 28/11/2023.
//

#ifndef CA3_BALLENTITY_CPP
#define CA3_BALLENTITY_CPP

#include "../ecm/Entity.h"
#include "Box2D/Box2D.h"
#include "../engine/GameEngine.h"

// Physics component for the BallEntity
class BallPhysicsComponent : public Component {
private:
    b2Body* body {};
    b2BodyDef bodyDef;

public:
    void Start() override {
        Component::Start();

        float rand_x = static_cast<float>(rand() % GameEngine::getInstance()->getScreenSize().x);
        float rand_y = static_cast<float>(rand() % GameEngine::getInstance()->getScreenSize().y);
        parent->getTransform().setPosition({rand_x, rand_y});

        // Set up the physics body
        bodyDef.type = b2_dynamicBody;  // Kinematic body for controlled motion
        bodyDef.position.Set(parent->getTransform().getPosition().x, parent->getTransform().getPosition().y);
//        body = GameEngine::getInstance()->getWorld().CreateBody(&bodyDef);

    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        // Update the position of the entity based on the kinematic body
        auto pos = body->GetPosition();
        parent->getTransform().setPosition({pos.x, pos.y});
    }
};

// Graphics component for the BallEntity
class BallGraphicsComponent : public Component {
private:
    float radius;
    sf::CircleShape shape;

public:
    explicit BallGraphicsComponent(float radius = 10.f) : radius(radius) {};

    void Start() override {
        Component::Start();

        // Set up the visual representation of the entity
        shape = sf::CircleShape(radius);
        auto randomColor = sf::Color(rand() % 255, rand() % 255, rand() % 255);
        shape.setFillColor(randomColor);
        shape.setOrigin(radius, radius);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        // Update the position and draw the shape
        shape.setPosition(parent->getTransform().getPosition());
        window->draw(shape);
    }
};

// Concrete BallEntity class
class BallEntity : public Entity {
public:
    explicit BallEntity() {
        // Set initial position of the entity
        getTransform().setPosition({static_cast<float>(GameEngine::getInstance()->getScreenSize().x / 2),
                                    static_cast<float>(GameEngine::getInstance()->getScreenSize().y / 2)});

        // Add physics and graphics components to the entity
        AddComponent(std::make_shared<BallPhysicsComponent>());
        AddComponent(std::make_shared<BallGraphicsComponent>());
    };
};

#endif //CA3_BALLENTITY_CPP
