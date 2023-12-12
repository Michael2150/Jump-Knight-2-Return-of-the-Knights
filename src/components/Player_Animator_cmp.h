//
// Created by ugwul on 10/12/2023.
//

#ifndef CA3_PLAYER_ANIMATOR_CMP_H
#define CA3_PLAYER_ANIMATOR_CMP_H

#include "../ecm/Component.h"
#include "Animation_cmp.h"
#include "Player_Controller_cmp.h"

class Player_Animator_cmp : public Component {

private:
    vector<Animation_cmp> animations;
    Animation_cmp* currentAnimation;
    bool flipped;

public:

    enum class animation_state
    {
        idle = 0,
        crouch = 1,
        run = 2,
        jump = 3,
        fall = 4,
    };

    void Start() override {
        Component::Start();

        // Create the animations
        Animation_cmp idleAnimation = Animation_cmp("resources/animations/player/idle.png", 0.5f, 10, sf::Vector2i(27, 40), 93, true);
        Animation_cmp crouchAnimation = Animation_cmp("resources/animations/player/crouch.png", 1.0f, 1, sf::Vector2i(27, 40), 0, false);
        Animation_cmp runAnimation = Animation_cmp("resources/animations/player/run.png", 0.8f, 10, sf::Vector2i(27, 40), 93, true);
        Animation_cmp jumpAnimation = Animation_cmp("resources/animations/player/jump.png", 0.8f, 3, sf::Vector2i(27, 40), 93, false);
        Animation_cmp fallAnimation = Animation_cmp("resources/animations/player/fall.png", 0.8f, 3, sf::Vector2i(27, 40), 93, true);

        // Add the animations to the vector
        animations.push_back(idleAnimation);
        animations.push_back(crouchAnimation);
        animations.push_back(runAnimation);
        animations.push_back(jumpAnimation);
        animations.push_back(fallAnimation);

        // Set the current animation
        currentAnimation = &animations[0];
    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        // Update the current animation
        currentAnimation->Update(deltaTime);

        currentAnimation->setPos(parent->getTransform()->getPosition());

        if (flipped) {
            currentAnimation->getSprite().setScale(-parent->getTransform()->getScale().x, parent->getTransform()->getScale().y);
        } else {
            currentAnimation->getSprite().setScale(parent->getTransform()->getScale().x, parent->getTransform()->getScale().y);
        }
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);

        // Render the current animation
        currentAnimation->Render(window);
    }

    void SetAnimation(animation_state state) {
        currentAnimation = &animations[static_cast<int>(state)];
    }

    void setFlip(bool flip) {
        flipped = flip;
    }
};

#endif //CA3_PLAYER_ANIMATOR_CMP_H
