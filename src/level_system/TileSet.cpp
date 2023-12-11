//
// Created by micha on 05/12/2023.
//
#include "TileSet.h"
#include "../engine/GameEngine.h"
#include "Box2D/Collision/Shapes/b2PolygonShape.h"
#include "Box2D/Dynamics/b2Fixture.h"

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

TileSet::TileSet(const std::vector <std::vector<int>>& tileIds, shared_ptr<TileSet> sourceTileSet) {
    this->texture = sourceTileSet->texture;

    // Set the scale so that all the tiles fit the width of the window, but keep the aspect ratio
    auto windowSize = GameEngine::getInstance()->getScreenSize();
    int gridWith = tileIds[0].size();
    int tileWidth = sourceTileSet->tiles[0].getTextureRect().width;
    this->scale = (float) windowSize.x / (float) (gridWith * tileWidth);

    parseTileIds(tileIds, sourceTileSet);
}

void TileSet::Render(sf::RenderWindow *window) {
    if (!this->shouldRender) return;

    Entity::Render(window);

    for (auto &tile : this->tiles) {
        window->draw(tile);
    }
}

void TileSet::parseTileIds(const vector<std::vector<int>> &tileIds, shared_ptr<TileSet> sourceTileSet) {
    // Bits on the far end of the 32-bit global tile ID are used for tile flags
    const unsigned FLIPPED_HORIZONTALLY_FLAG  = 0x80000000;
    const unsigned FLIPPED_VERTICALLY_FLAG    = 0x40000000;
    const unsigned FLIPPED_DIAGONALLY_FLAG    = 0x20000000;

    // Loop through each row
    for (int row = 0; row < tileIds.size(); row++) {
        // Loop through each column
        for (int column = 0; column < tileIds[row].size(); column++) {
            // Get the tile id
            int tileId = tileIds[row][column];

            // Check if the tile is flipped horizontally
            bool flippedHorizontally = (tileId & FLIPPED_HORIZONTALLY_FLAG) != 0;

            // Check if the tile is flipped vertically
            bool flippedVertically = (tileId & FLIPPED_VERTICALLY_FLAG) != 0;

            // Check if the tile is flipped diagonally
            bool flippedDiagonally = (tileId & FLIPPED_DIAGONALLY_FLAG) != 0;

            // Remove the flags from the tile id
            tileId &= ~(FLIPPED_HORIZONTALLY_FLAG | FLIPPED_VERTICALLY_FLAG | FLIPPED_DIAGONALLY_FLAG );

            // Get the tile sprite
            if (tileId == 0) continue;

            sf::Sprite tile = sourceTileSet->getTile(tileId);

            // Set the scale of the tile
            tile.setScale(this->scale, this->scale);

            // Set the origin to the center of the tile
            tile.setOrigin(tile.getLocalBounds().width / 2, tile.getLocalBounds().height / 2);

            auto tileScale = tile.getScale();

            if (flippedHorizontally) {
                // Flip the tile horizontally
                tile.setScale(-tileScale.x, tileScale.y);
            }

            tileScale = tile.getScale();

            if (flippedVertically) {
                // Flip the tile vertically
                tile.setScale(tileScale.x, -tileScale.y);
            }

            tileScale = tile.getScale();

            if (flippedDiagonally) {
                // Flip the tile horizontally and rotate it 90 degrees
                tile.setScale(-tileScale.x, tileScale.y);
                tile.rotate(90);
            }

            // Set the position of the tile
            tile.setPosition(column * tile.getGlobalBounds().width + tile.getGlobalBounds().width / 2,
                             row * tile.getGlobalBounds().height + tile.getGlobalBounds().height / 2);

            // Add the tile to the vector of tiles
            this->tiles.push_back(tile);
        }
    }
}

sf::Sprite TileSet::getTile(int tileId) {
    if (tileId == 0) {
        return {};
    }

    // Create a new sprite
    sf::Sprite tile(this->texture);

    // Set the texture rectangle of the sprite
    sf::Sprite sourceTile = this->tiles[tileId - 1];
    tile.setTextureRect(sourceTile.getTextureRect());

    return tile;
}

void TileSet::setTileSetAsStaticBody(b2World *world) {
    // Loop through each tile
    int i = 0;

    for (auto &tile : this->tiles) {
        if (tile.getPosition().x == 0 && tile.getPosition().y == 0) continue;

        // Create a body definition
        b2BodyDef bodyDef;
        bodyDef.type = b2_staticBody;
        bodyDef.bullet = true;
        auto physicsPos = PhysicsEngine::GraphicsToPhysics(tile.getPosition());
        bodyDef.position.Set(physicsPos.x, physicsPos.y);

        // Create the body
        b2Body* body = world->CreateBody(&bodyDef);

        // Create the shape
        b2PolygonShape shape;
        auto physicsSize = PhysicsEngine::GraphicsToPhysics({tile.getGlobalBounds().width / 2, tile.getGlobalBounds().height / 2});
        shape.SetAsBox(physicsSize.x, physicsSize.y);

        // Create the fixture
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.f;
        fixtureDef.restitution = 0.f;
        body->CreateFixture(&fixtureDef);

        i++;
    }

    cout << "Created " << i << " static bodies" << endl;
}
