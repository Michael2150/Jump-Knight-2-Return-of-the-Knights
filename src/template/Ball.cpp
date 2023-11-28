//
// Created by micha on 28/11/2023.
//

#ifndef CA3_BALLENTITY_CPP
#define CA3_BALLENTITY_CPP

#include "../ecm/Entity.h"
#include "Box2D/Box2D.h"

class BallPhysicsComponent : public Component {
public:
    void Start() override {
        Component::Start();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);
    }
};

class BallGraphicsComponent : public Component {
public:
    void Start() override {
        Component::Start();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);
    }
};

class BallEntity : public Entity{
public:
    BallEntity() {
        AddComponent(make_shared<BallPhysicsComponent>());
        AddComponent(make_shared<BallGraphicsComponent>());
    };

    void Start() override {
        Entity::Start();
    }

    void Update(float deltaTime) override {
        Entity::Update(deltaTime);
    }

    void Render(sf::RenderWindow *window) override {
        Entity::Render(window);
    }
};


#endif //CA3_BALLENTITY_CPP
