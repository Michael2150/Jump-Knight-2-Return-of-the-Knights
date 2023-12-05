//
// Created by micha on 05/12/2023.
//

#include "LevelMap.h"

#include <utility>
#include <fstream>
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

LevelMap::LevelMap(string levelMapPath, ) {
    this->levelMapPath = std::move(levelMapPath);

    // Read in the file as a json object
    std::ifstream i(this->levelMapPath);
    string str((std::istreambuf_iterator<char>(i)), std::istreambuf_iterator<char>());
    json j = json::parse(str);


    // Get the layers from the json object
    auto layers = j["layers"];

    // Loop through each layer
    for (auto &layer : layers) {
        // Get the layer name
        string layerName = layer["name"];

        // Get the layer data
        auto layerData = layer["data"];

        // Get the layer width
        int layerWidth = layer["width"];

        // Get the layer height
        int layerHeight = layer["height"];

        // Create a vector to store the tile ids
        std::vector<std::vector<int>> tileIds;

        // Loop through each row
        for (int row = 0; row < layerHeight; row++) {
            // Create a vector to store the tile ids for this row
            std::vector<int> tileIdsRow;

            // Loop through each column
            for (int column = 0; column < layerWidth; column++) {
                // Get the tile id
                int tileId = layerData[(row * layerWidth) + column];

                // Add the tile id to the vector
                tileIdsRow.push_back(tileId);
            }

            // Add the vector of tile ids to the vector of tile ids
            tileIds.push_back(tileIdsRow);
        }

        // Add the layer name and the vector of tile ids to the map
        this->levelMap.insert(std::pair<string, std::vector<std::vector<int>>>(layerName, tileIds));
    }
}

void LevelMap::Render(sf::RenderWindow *window) {
    Entity::Render(window);

}
