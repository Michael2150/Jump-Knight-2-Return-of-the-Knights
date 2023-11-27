#include <iostream>
#include "GameEngine.h"

GameEngine* GameEngine::instance = nullptr;

GameEngine::GameEngine() {
    auto Ball = new Entity();
}

void GameEngine::Start(int width, int height, std::string title) {
    std::cout << "Starting game engine..." << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Title: " << title << std::endl;

    this->window = new sf::RenderWindow(sf::VideoMode({static_cast<unsigned int>(width),
                                                       static_cast<unsigned int>(height)}), title);
    auto timer = sf::Clock();

    // Start all the entities and components here:
    for (auto &entity : entities) {
        entity->Start();
    }

    while (window->isOpen()) {
        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        // Update all the entities and components here
        for (auto &entity : entities) {
            entity->Update(timer.restart().asSeconds());
        }

        window->clear(sf::Color::Black);

        // Render all the entities and components here
        for (auto &entity : entities) {
            entity->Render();
        }

        window->display();
    }
}

GameEngine *GameEngine::getInstance() {
    if (instance == nullptr) {
        instance = new GameEngine();
    }
    return instance;
}

sf::Vector2<float> GameEngine::getScreenSize() {
    return {static_cast<float>(window->getSize().x),
            static_cast<float>(window->getSize().y)};
}