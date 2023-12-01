//
// Created by micha on 30/11/2023.
//

#ifndef CA3_COMPONENT_PHYSICSSHAPERENDERER_H
#define CA3_COMPONENT_PHYSICSSHAPERENDERER_H

#include <utility>

#include "Box2D/Dynamics/b2Body.h"
#include "SFML/Graphics/Shape.hpp"
#include "../ecm/Component.h"
#include "Component_Physics.h"

class Component_PhysicsShapeRenderer : public Component {
private:
    Component_Physics* physics;
    sf::Shape* shape;

public:
    explicit Component_PhysicsShapeRenderer(Component_Physics* physics, sf::Shape* shape) {
        this->physics = physics;
        this->shape = shape;
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        b2Body* body = physics->getBody();
        shape->setPosition(body->GetPosition().x, body->GetPosition().y);
        shape->setRotation(body->GetAngle());
    }

    void Render(sf::RenderWindow* window) override {
        Component::Render(window);

        window->draw(*shape);
    }
};

#endif //CA3_COMPONENT_PHYSICSSHAPERENDERER_H
