//
// Created by micha on 28/11/2023.
//

#ifndef CA3_FPS_COUNTER_CPP
#define CA3_FPS_COUNTER_CPP

#include "../ecm/Entity.h"
#include "SFML/Graphics/Text.hpp"

class FPSCounter : public Entity {
private:
    sf::Text text;
    sf::Font font;
    float time_interval = 0.05f;
    float time_elapsed = 0.f;
public:
    FPSCounter() {
        font.loadFromFile("resources/fonts/arial.ttf");
        text.setFont(font);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::Green);
        text.setPosition(5, 5);
    }

    void Update(float deltaTime) override {
        Entity::Update(deltaTime);

        if (time_elapsed < time_interval) {
            time_elapsed += deltaTime;
            return;
        }

        // Update the FPS counter
        text.setString("FPS: " + std::to_string(1.0f / deltaTime) + " (" + std::to_string(deltaTime) + "s)");
        time_elapsed = 0.f;
    }

    void Render(sf::RenderWindow* window) override {
        Entity::Render(window);

        // Render the FPS counter
        window->draw(text);
    }
};

#endif //CA3_FPS_COUNTER_CPP