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
public:
    Transform_Component() : position(sf::Vector2f(0, 0)), rotation(0), scale(sf::Vector2f(1, 1)) {}
    Transform_Component(sf::Vector2f position, float rotation, sf::Vector2f scale) : position(position), rotation(rotation), scale(scale) {}

    sf::Vector2f getPosition() { return position; }
    void setPosition(sf::Vector2f position) { this->position = position; }

    float getRotation() const { return rotation; }
    void setRotation(float rotation) { this->rotation = rotation; }

    sf::Vector2f getScale() { return scale; }
    void setScale(sf::Vector2f scale) { this->scale = scale; }
};

#endif //CA3_TRANSFORM_H
