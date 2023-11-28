//
// Created by micha on 28/11/2023.
//

#ifndef CA3_COMP_PHYSICS_RENDERER_H
#define CA3_COMP_PHYSICS_RENDERER_H

#include "Component.h"
#include "Box2D/Dynamics/b2Body.h"
#include "SFML/Graphics/Shape.hpp"

using namespace std;

class comp_physics_renderer : public Component {
private:
    sf::CircleShape* shape;
    b2Body* body;

public:
    comp_physics_renderer(sf::CircleShape* shape, b2Body* body) {
        this->shape = shape;
        this->body = body;
    }

    void Start() override {
        Component::Start();
    }

    void Update(float deltaTime) override {
        shape->setPosition(body->GetPosition().x, body->GetPosition().y);
        shape->setRotation(body->GetAngle() * 180 / b2_pi);
        Component::Update(deltaTime);
    }

    void Render(sf::RenderWindow* window) override {
        window->draw(*shape);
        Component::Render(window);
    }
};

#endif //CA3_COMP_PHYSICS_RENDERER_H
