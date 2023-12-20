//
// Created by micha on 12/12/2023.
//

#ifndef CA3_PLAYER_DOOR_CHECK_CMP_H
#define CA3_PLAYER_DOOR_CHECK_CMP_H

#include "../ecm/Component.h"
#include "../level_system/TileSet.h"
#include "../engine/GameEngine.h"

class Player_Door_Check_cmp : public Component {
public:
    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        auto pos = parent->getTransform()->getPosition();
        auto scene = GameEngine::getInstance()->GetCurrentScene();
        auto special_layer = scene->getLevelMap()->getLayer("special");
        auto isTouchingDoor = special_layer->isOnTile(pos, static_cast<int>(SpecialTile::END_BLOCK));

        auto last_index = 3;

        if (isTouchingDoor) {
            auto current_scene_index = GameEngine::getInstance()->GetCurrentSceneIndex();

            if (current_scene_index == last_index) {
                GameEngine::getInstance()->SetActiveScene(0);
                return;
            }

            GameEngine::getInstance()->SetActiveScene(current_scene_index + 1);
        }
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        // Render a small dot on the player's position
        auto pos = parent->getTransform()->getPosition();
        sf::CircleShape shape(5);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(pos.x, pos.y);
        window->draw(shape);
    }
};

#endif //CA3_PLAYER_DOOR_CHECK_CMP_H
