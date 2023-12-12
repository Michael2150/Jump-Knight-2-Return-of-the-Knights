//
// Created by micha on 28/11/2023.
//

#ifndef CA3_TRANSFORM_H
#define CA3_TRANSFORM_H

#include "Component.h"
#include "SFML/System/Vector2.hpp"

class Transform_Component : public Component {
private:
    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

    bool pos_changed = false;
    bool rot_changed = false;
    bool scale_changed = false;

public:
    explicit Transform_Component() :
        position(sf::Vector2f(0, 0)),
        rotation(0),
        scale(sf::Vector2f(1, 1)) {}

    Transform_Component(sf::Vector2f position, float rotation, sf::Vector2f scale) :
        position(position),
        rotation(rotation),
        scale(scale) {}

    sf::Vector2f getPosition() { return position; }
    void setPosition(sf::Vector2f position) { this->position = position; }
    float getRotation() const { return rotation; }
    void setRotation(float rotation) { this->rotation = rotation; }
    sf::Vector2f getScale() { return scale; }
    void setScale(sf::Vector2f scale) { this->scale = scale; }

    void PositionChanged() { pos_changed = true; }
    void RotationChanged() { rot_changed = true; }
    void ScaleChanged() { scale_changed = true; }

    bool hasPosChanged() const { return pos_changed; }
    bool hasRotChanged() const { return rot_changed; }
    bool hasScaleChanged() const { return scale_changed; }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        pos_changed = false;
        rot_changed = false;
        scale_changed = false;
    }
};

#endif //CA3_TRANSFORM_H
