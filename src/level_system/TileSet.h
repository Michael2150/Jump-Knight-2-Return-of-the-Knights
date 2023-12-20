//
// Created by micha on 05/12/2023.
//

#ifndef CA3_TILESET_H
#define CA3_TILESET_H

#include "../ecm/Entity.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Box2D/Dynamics/b2World.h"
#include "Box2D/Dynamics/b2Body.h"

enum class SpecialTile {
    SPAWN = 95,
    END_BLOCK = 96,
    TEXT_POSITION = 69,
};


class TileSet : public Entity {
private:
    float scale = 1.0f;


public:
    bool shouldRender = true;
    sf::Texture texture;
    vector<sf::Sprite> tiles;
    std::vector<std::vector<int>> tileIds;

    explicit TileSet(const string& filePath, const sf::Vector2u& tileSize, const sf::Vector2u& size);
    TileSet(const std::vector<std::vector<int>>& tileIds, shared_ptr<TileSet> sourceTileSet);
    void Render(sf::RenderWindow *window) override;

    void parseTileIds(const std::vector<std::vector<int>>& tileIds, shared_ptr<TileSet> sourceTileSet);
    static int parseTileId(int tileId);
    sf::Sprite getTile(int tileId);

    void setTileSetAsStaticBody(b2World *world);

    sf::Vector2i getTileIndexFromPosition(sf::Vector2f position);
    int getTileIdFromPosition(sf::Vector2f position);
    bool isOnTile(sf::Vector2f position, int tileId);
    sf::Vector2f getTilePosition(int tileId);
};

#endif //CA3_TILESET_H
