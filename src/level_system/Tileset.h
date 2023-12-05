//
// Created by micha on 05/12/2023.
//

#ifndef CA3_TILESET_H
#define CA3_TILESET_H

#include <string>
#include <memory>
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

class Tileset {
private:
    std::string tilesetPath;
    std::shared_ptr<sf::Image> tileset;
    std::shared_ptr<sf::Texture> texture;

public:
    explicit Tileset(std::string tilesetPath);

    std::shared_ptr<sf::Texture> getTexture() {
        return texture;
    }
};

#endif //CA3_TILESET_H
