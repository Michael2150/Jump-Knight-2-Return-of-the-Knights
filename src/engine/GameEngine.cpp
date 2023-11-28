#include <iostream>
#include <memory>
#include <iomanip>
#include "GameEngine.h"
#include "../template/Ball.cpp"

GameEngine* GameEngine::instance = nullptr;

void GameEngine::Initialize(int width, int height, const std::string &title) {
    std::cout << "Initializing game engine..." << std::endl;

    // Create the game window
    this->window = new sf::RenderWindow(sf::VideoMode({static_cast<unsigned int>(width),
                                                       static_cast<unsigned int>(height)}), title);

    // Create the game physics world
    world = new b2World(b2Vec2(0.0f, 9.8f));

    std::cout << "Game engine initialized!" << std::endl;
}

void GameEngine::Start() {
    std::cout << "Starting game engine..." << std::endl;

    // Create 50 balls
    for (int i = 0; i < 50; i++){
        auto ball = std::make_shared<BallEntity>();
        entities.push_back(ball);
    }

    auto timer = sf::Clock();

    // Start all the entities and components here:
    for (const auto& entity : entities) {
        entity->Start();
    }

    auto delta_time = timer.restart().asSeconds();

    std::cout << "Game started up in " << std::fixed << std::setprecision(6) << delta_time << " seconds." << std::endl;

    while (window->isOpen()) {
        delta_time = timer.restart().asSeconds();

        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        // Update all the entities and components here
        for (const auto& entity : entities) {
            entity->Update(delta_time);
        }

        window->clear(sf::Color::Black);

        world->Step(1.0f / 60.0f, 8, 3);

        // Render all the entities and components here
        for (const auto& entity : entities) {
            entity->Render(window);
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
