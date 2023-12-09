//
// Created by micha on 05/12/2023.
//
#include "TileSet.h"
#include "../engine/GameEngine.h"

TileSet::TileSet(const string& filePath, const sf::Vector2u& tileSize, const sf::Vector2u& size) {
    this->texture.loadFromFile(filePath);

    // Set the scale so the all the tiles fit the width of the window
    auto windowSize = GameEngine::getInstance()->getScreenSize();
    this->scale = (float) windowSize.x / (float) (tileSize.x * size.x);
    this->scale /= 3;

    // Loop through each tile
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {

            // Create a sprite for the tile
            sf::Sprite sprite;
            sprite.setTexture(this->texture);
            sprite.setTextureRect(sf::IntRect(x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y));
            sprite.setScale(this->scale, this->scale);
            sprite.setPosition(x * tileSize.x * this->scale, y * tileSize.y * this->scale);

            // Add the sprite to the vector of sprites
            this->tiles.push_back(sprite);
        }
    }
}

TileSet::TileSet(const std::vector <std::vector<int>>& tileIds, const TileSet& sourdceTileSet) {
    this->texture = sourdceTileSet.texture;

    this->tiles = std::vector<sf::Sprite>();
}

void TileSet::Render(sf::RenderWindow *window) {
    if (!this->shouldRender) return;

    Entity::Render(window);

    for (auto &tile : this->tiles) {
        window->draw(tile);
    }
}
