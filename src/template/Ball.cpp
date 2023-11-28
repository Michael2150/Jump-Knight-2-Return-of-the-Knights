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
    b2Vec2 initialVelocity; // Store initial velocity

public:
    void Start() override {
        Component::Start();

        // Set up the physics body
        bodyDef.type = b2_kinematicBody;  // Kinematic body for controlled motion
        auto pos = parent->getTransform().getPosition();
        bodyDef.position.Set(pos.x, pos.y);
        body = GameEngine::getInstance()->getWorld().CreateBody(&bodyDef);

        // Set initial velocity in a random direction with a fixed magnitude
        float angle = static_cast<float>(rand() % 360); // Random angle in degrees
        float magnitude = 500.f; // Adjust as needed
        initialVelocity = b2Vec2(magnitude * std::cos(angle * b2_pi / 180.0f),
                                 magnitude * std::sin(angle * b2_pi / 180.0f));

        // Apply initial velocity
        body->SetLinearVelocity(initialVelocity);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        // Update the position of the entity based on the kinematic body
        auto pos = body->GetPosition();
        parent->getTransform().setPosition({pos.x, pos.y});

        // Check if the ball touches the screen edges and make it bounce
        auto screenSize = GameEngine::getInstance()->getScreenSize();
        if (pos.x < 0 || pos.x > screenSize.x || pos.y < 0 || pos.y > screenSize.y) {
            // Reverse the velocity component perpendicular to the edge
            if (pos.x < 0 || pos.x > screenSize.x) {
                initialVelocity.x *= -1;
            }
            if (pos.y < 0 || pos.y > screenSize.y) {
                initialVelocity.y *= -1;
            }

            // Apply the updated velocity
            body->SetLinearVelocity(initialVelocity);
        }
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
        shape.setFillColor(sf::Color::Red);
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
