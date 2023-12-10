//
// Created by ugwul on 09/12/2023.
//

#ifndef CA3_ANIMATION_CMP_H
#define CA3_ANIMATION_CMP_H

#include "../ecm/Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Animation_cmp : public Component {
private:
    string file_name;
    float frame_time;
    int frame_count;
    int current_frame;
    float current_time{};
    bool loop;
    sf::Texture* texture;
    sf::IntRect* frames;
    sf::Sprite* sprite;

public:
    explicit Animation_cmp(string file_name, float speed, int frame_count, sf::Vector2i frame_size, int frame_offset, bool loop){
        this->file_name = file_name;
        this->frame_time = (1.0f / 24.0f)*(1.0f/speed);
        this->frame_count = frame_count;
        this->loop = loop;
        this->current_frame = 0;
        frame_size = sf::Vector2i(10, 10);
        speed = 1;
        frame_offset = 0;

        texture = new sf::Texture();
        if(!texture->loadFromFile(file_name)){
            std::cout << "Failed to load texture: " << file_name << std::endl;
            return;
        }

        sprite = new sf::Sprite();
        sprite->setTexture(*texture);

        this->frames = new sf::IntRect[frame_count];
        for(int i = 0; i < frame_count; i++){
            frames[i] = sf::IntRect(i*frame_size.x + i*frame_offset, 0, frame_size.x, frame_size.y);
        }

        sprite->setTextureRect(frames[0]);
        sprite->setOrigin(frame_size.x/2, frame_size.y/2);

    }

    void Start() override {
        Component::Start();

    }

    void Update(float deltaTime) override {
        Component::Update(deltaTime);

        current_time += deltaTime;
        if (current_time >= frame_time) {
            current_time = 0;
            current_frame++;
            if (current_frame >= frame_count) {
                if(loop){
                    current_frame = 0;
                } else {
                    current_frame = frame_count - 1;
                }
            }
            sprite->setTextureRect(frames[current_frame]);
        }
    }

    void Render(sf::RenderWindow *window) override {
        Component::Render(window);
        window->draw(*sprite);
    }

    sf::Sprite& getSprite(){
        return *sprite;
    }
};

#endif //CA3_ANIMATION_CMP_H
