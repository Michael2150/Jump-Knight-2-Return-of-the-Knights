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
#include "Box2D/Dynamics/Contacts/b2Contact.h"
#include "../engine/GameEngine.h"


class hello_world_component : public Component {

private:
    sf::Text text;
    b2World* world;
    float total_time = 0.0f;

    b2Body* ballBody{};
    sf::CircleShape ballShape;
    sf::RectangleShape* groundShape{};
public:
    explicit hello_world_component(b2World* world) : world(world) {}

    void Start() override {
        Component::Start();

        // Create the text
        text.setString("Hello World!");
        text.setFont( GameEngine::getInstance()->getFont());
        text.setPosition(100.0f, 0.f);
        text.setCharacterSize(18);

        // Create the ball
        auto radius = 20.0f;
        auto size = Vector2f(radius * 2.0f, radius * 2.0f);

        // Create the bounds of the world
        auto screenSize = GameEngine::getInstance()->getScreenSize();
        auto groundSize = Vector2f(screenSize.x, 10.0f);
        auto groundPosition = Vector2f(screenSize.x * 0.5f, screenSize.y - groundSize.y * 0.5f);

        // Create the ground
        b2BodyDef groundBodyDef;
        groundBodyDef.type = b2_staticBody;
        groundBodyDef.position.Set(PhysicsEngine::GraphicsToPhysics(groundPosition.x), PhysicsEngine::GraphicsToPhysics(groundPosition.y));
        auto groundBody = world->CreateBody(&groundBodyDef);

        // Create the ground fixture
        b2PolygonShape groundBox;
        groundBox.SetAsBox(PhysicsEngine::GraphicsToPhysics(groundSize.x * 0.5f), PhysicsEngine::GraphicsToPhysics(groundSize.y * 0.5f));
        groundBody->CreateFixture(&groundBox, 0.0f);

        // Create the ground shape
        groundShape = new sf::RectangleShape(groundSize);
        groundShape->setOrigin(groundSize * 0.5f);
        groundShape->setPosition(groundPosition);
        groundShape->setFillColor(sf::Color::Green);

        // Create the ball
        b2BodyDef ballBodyDef;
        ballBodyDef.type = b2_dynamicBody;
        auto ballPosition = Vector2f(screenSize.x * 0.5f, screenSize.y * 0.2f);
        auto physicsPosition = PhysicsEngine::GraphicsToPhysics(ballPosition);
        ballBodyDef.position.Set(physicsPosition.x, physicsPosition.y);
        ballBody = world->CreateBody(&ballBodyDef);

        // Create the ball fixture
        b2CircleShape ballCircle;
        ballCircle.m_radius = PhysicsEngine::GraphicsToPhysics(radius);
        b2FixtureDef ballFixtureDef;
        ballFixtureDef.shape = &ballCircle;
        ballFixtureDef.density = 1.0f;
        ballFixtureDef.friction = 0.3f;
        ballBody->CreateFixture(&ballFixtureDef);

        // Create the ball shape
        ballShape.setRadius(radius);
        ballShape.setOrigin(size * 0.5f);
        ballShape.setFillColor(sf::Color::Red);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        total_time += 1.0f / 60.0f;

        text.setString("a = (x: " + to_string(world->GetGravity().x) + ", y: " + to_string(world->GetGravity().y) + ")" +
                     "\nv = (x: " + to_string(ballBody->GetLinearVelocity().x) + ", y: " + to_string(ballBody->GetLinearVelocity().y) + ")" +
                     "\np = (x: " + to_string(ballBody->GetPosition().x) + ", y: " + to_string(ballBody->GetPosition().y) + ")" +
                        "\nt = " + to_string(total_time));

        ballShape.setPosition(PhysicsEngine::PhysicsToGraphics(ballBody->GetPosition()));
        ballShape.setRotation(ballBody->GetAngle() * 180.0f / b2_pi);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        window->draw(ballShape);
        window->draw(*groundShape);
        window->draw(text);
    }
};

#endif //CA3_HELLO_WORLD_COMPONENT_H
