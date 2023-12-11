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

class TileSet : public Entity {
private:
    float scale = 1.0f;

public:
    bool shouldRender = true;
    sf::Texture texture;
    vector<sf::Sprite> tiles;

    explicit TileSet(const string& filePath, const sf::Vector2u& tileSize, const sf::Vector2u& size);
    TileSet(const std::vector<std::vector<int>>& tileIds, shared_ptr<TileSet> sourceTileSet);
    void Render(sf::RenderWindow *window) override;

    void parseTileIds(const std::vector<std::vector<int>>& tileIds, shared_ptr<TileSet> sourceTileSet);
    sf::Sprite getTile(int tileId);

    void setTileSetAsStaticBody(b2World *world);

    bool isInTile(sf::Vector2f position){
        return false;
    }
    bool isInTile(sf::Vector2f position, int tileId){
        return false;
    }
    bool isInTile(sf::Vector2f position, std::vector<int> tileIds){
        return false;
    }
    bool isNotInTile(sf::Vector2f position){
        return false;
    }
    bool isNotInTile(sf::Vector2f position, int tileId){
        return false;
    }
    bool isNotInTile(sf::Vector2f position, std::vector<int> tileIds){
        return false;
    }
};

#endif //CA3_TILESET_H
