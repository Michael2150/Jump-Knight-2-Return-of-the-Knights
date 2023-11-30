//
// Created by micha on 30/11/2023.
//

#ifndef CA3_TEXT_COMPONENT_H
#define CA3_TEXT_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "../ecm/Component.h"

using namespace std;
using namespace sf;

class TextComponent : public Component {
private:
    Font font;
    Text text;
public:
    void Start() override {
        Component::Start();

        font.loadFromFile("resources/fonts/arial.ttf");
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        text.setPosition(parent->getTransform().getPosition());
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);
        window->draw(text);
    }

    void setText(string str) {
        text.setString(str);
    }

    void setCharacterSize(int size) {
        text.setCharacterSize(size);
    }

    void setFillColor(Color color) {
        text.setFillColor(color);
    }

    void setStyle(Text::Style style) {
        text.setStyle(style);
    }

    void setOrigin(Vector2f origin) {
        text.setOrigin(origin);
    }
};

#endif //CA3_TEXT_COMPONENT_H
