//
// Created by micha on 05/12/2023.
//

#include <memory>
#include "Tileset.h"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

Tileset::Tileset(std::string tilesetPath) {
    this->tilesetPath = tilesetPath;
    this->tileset = std::make_shared<sf::Image>();
    tileset->loadFromFile(tilesetPath);
    this->texture = std::make_shared<sf::Texture>();
    texture->loadFromImage(*tileset);
}
