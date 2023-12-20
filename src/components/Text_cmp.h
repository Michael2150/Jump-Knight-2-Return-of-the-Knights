//
// Created by micha on 30/11/2023.
//

#ifndef CA3_TEXT_CMP_H
#define CA3_TEXT_CMP_H

#include "SFML/Graphics.hpp"
#include "../ecm/Component.h"

using namespace std;
using namespace sf;

class Text_cmp : public Component {
private:
    Font font;
    Text text;
    string fontPath = "resources/fonts/arial.ttf";
    int characterSize = 12;
    Color color = Color::White;

public:
    explicit Text_cmp(string Text) {
        text.setString(Text);
    }

    explicit Text_cmp(string Text, int characterSize, Color color, string fontPath) {
        text.setString(Text);

        this->fontPath = fontPath;
        this->characterSize = characterSize;
        this->color = color;
    }

    void Start() override {
        Component::Start();

        font.loadFromFile(fontPath);

        text.setFont(font);
        text.setCharacterSize(characterSize);
        text.setFillColor(color);
        text.setOrigin(0, 0);
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);
        text.setPosition(parent->getTransform()->getPosition());
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);
        window->draw(text);
    }

    void setText(string str) {
        text.setString(str);
    }
};

#endif //CA3_TEXT_CMP_H
