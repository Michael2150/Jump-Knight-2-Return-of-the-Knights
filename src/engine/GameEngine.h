//
// Created by micha on 26/11/2023.
//

#ifndef CA3_GAMEENGINE_H
#define CA3_GAMEENGINE_H

#include "../scenes/Scene.h"
#include "Box2D/Dynamics/b2World.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class GameEngine {
private:
    static GameEngine* instance;
    RenderWindow* window;
    vector<shared_ptr<Scene>> scenes;
    Scene* current_scene;
    string title;
    Font font;

public:
    explicit GameEngine() {
        window = nullptr;
        current_scene = nullptr;
        scenes = vector<shared_ptr<Scene>>();

        if (!font.loadFromFile("resources/fonts/arial.ttf")) {
            cout << "Failed to load font" << endl;
        }
    }

    static GameEngine* getInstance();

    void Initialize(int width, int height, const std::string& title);
    void Start();

    RenderWindow& getWindow() { return *window; }
    Vector2i getScreenSize() { return {static_cast<int>(window->getSize().x), static_cast<int>(window->getSize().y)}; }

    void SetActiveScene(int index) {
        current_scene = scenes[index].get();

        if (!current_scene->HasStarted()) {
            current_scene->Start();
        }
    }
    Scene* GetCurrentScene() { return current_scene; }

    template <class T>
    void CreateScene() { // Creates and adds a scene of type T to the game engine.
        static_assert(std::is_base_of<Scene, T>::value, "T must be of type Scene or derived from Scene");

        shared_ptr<T> scene = make_shared<T>();
        scenes.push_back(scene);
        scene->Initialize();
    }

    Font& getFont() { return font; }
};

#endif //CA3_GAMEENGINE_H
