#include <iostream>
#include <memory>
#include <iomanip>
#include "GameEngine.h"
#include "../game/Game.h"

GameEngine* GameEngine::instance = nullptr;

void GameEngine::Initialize(int width, int height, const std::string &title) {
    auto timer = sf::Clock();

    this->title = title;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), this->title, sf::Style::Default);
    this->window->setFramerateLimit(60);

    // Create the scenes here:
    CreateScene<MenuScene>(); // Scene [0]
    CreateScene<Level1>(); // Scene [1]
    CreateScene<Level2>(); // Scene [2]
    CreateScene<Level3>(); // Scene [3]
    CreateScene<EndScene>(); // Scene [4]

    cout << "Game engine initialized in " << std::fixed << std::setprecision(6) << timer.restart().asSeconds() << " seconds." << endl;
}

void GameEngine::Start() {
    std::cout << "Starting game engine..." << std::endl;

    auto timer = sf::Clock();

    SetActiveScene(0); // Menu scene

    auto delta_time = 0.f;
    while (window->isOpen()) {
        delta_time = timer.restart().asSeconds();

        sf::Event event{};
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window->close();
                }

                if (event.key.code == sf::Keyboard::Num1) {
                    SetActiveScene(0);
                }
                if (event.key.code == sf::Keyboard::Num2) {
                    SetActiveScene(1);
                }
                if (event.key.code == sf::Keyboard::Num3) {
                    SetActiveScene(2);
                }
                if (event.key.code == sf::Keyboard::Num4) {
                    SetActiveScene(3);
                }
                if (event.key.code == sf::Keyboard::Num5) {
                    SetActiveScene(4);
                }
            }
        }

        current_scene->Update(delta_time);

        window->clear(sf::Color::Black);

        current_scene->Render(window);

        window->display();

        window->setTitle(this->title + " | FPS: " + std::to_string(1.f / delta_time));
    }
}

GameEngine *GameEngine::getInstance() {
    if (instance == nullptr) {
        instance = new GameEngine();
    }
    return instance;
}
