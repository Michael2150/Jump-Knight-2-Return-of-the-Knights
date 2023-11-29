#ifndef CA3_OBSTACLEENTITY_CPP
#define CA3_OBSTACLEENTITY_CPP

#include "../ecm/Entity.h"
#include "Box2D/Box2D.h"
#include "../engine/GameEngine.h"

// Physics component for the ObstacleEntity
class ObstaclePhysicsComponent : public Component {
private:
    b2Body* body {};
    b2BodyDef bodyDef;
public:

    void Start() override {
        Component::Start();

        auto transform = parent->getTransform();

        // Set up the physics body
        bodyDef.type = b2_staticBody;  // Kinematic body for controlled motion
        bodyDef.position.Set(parent->getTransform().getPosition().x, parent->getTransform().getPosition().y);
        body = GameEngine::getInstance()->getWorld().CreateBody(&bodyDef);

        b2PolygonShape boxShape;
        boxShape.SetAsBox(transform.getScale().x, transform.getScale().y);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &boxShape;
        fixtureDef.density = 1.f;
        fixtureDef.friction = 0.7f;
        fixtureDef.restitution = 0.2f;

        body->CreateFixture(&fixtureDef);

        // Add the physics body to the world
        GameEngine::getInstance()->getWorld().CreateBody(&bodyDef);
    }
};

// Graphics component for the ObstacleEntity
class ObstacleGraphicsComponent : public Component {
private:
    sf::RectangleShape shape;
public:
    void Start() override {
        Component::Start();

        // Set up the visual representation of the entity
        shape = sf::RectangleShape(parent->getTransform().getScale());
        shape.setPosition(parent->getTransform().getPosition());
        shape.setFillColor(sf::Color::Red);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        // Draw the entity to the window
        window->draw(shape);
    }
};

// The ObstacleEntity class
class ObstacleEntity : public Entity {
public:
    explicit ObstacleEntity(IntRect rect) {
        transform.setScale({static_cast<float>(rect.width), static_cast<float>(rect.height)});
        transform.setPosition({static_cast<float>(rect.left), static_cast<float>(rect.top)});

        AddComponent(std::make_shared<ObstaclePhysicsComponent>());
        AddComponent(std::make_shared<ObstacleGraphicsComponent>());
    }
};

#endif //CA3_OBSTACLEENTITY_CPP
