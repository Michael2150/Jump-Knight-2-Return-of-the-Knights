//
// Created by micha on 11/12/2023.
//

#ifndef CA3_PLAYER_CAMERA_H
#define CA3_PLAYER_CAMERA_H

#include "../ecm/Component.h"
#include "../engine/GameEngine.h"

class Player_Camera_cmp : public Component {
private:
    float y_offset = -100.f;

public:
    void Start() override {
        Component::Start();
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        auto player_pos = parent->getTransform().getPosition();
        auto viewport = GameEngine::getInstance()->getWindow().getView();

        viewport.setCenter(viewport.getCenter().x, player_pos.y + y_offset);

        GameEngine::getInstance()->getWindow().setView(viewport);
    }
};

#endif //CA3_PLAYER_CAMERA_H
