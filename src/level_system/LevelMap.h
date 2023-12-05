//
// Created by micha on 05/12/2023.
//

#ifndef CA3_LEVELMAP_H
#define CA3_LEVELMAP_H

#include <string>
#include <map>
#include <vector>
#include "../ecm/Entity.h"

using std::string;

class LevelMap: public Entity{
private:
    string levelMapPath;

    // Stores the layer name, and the tile ids for each tile in the layer
    std::map<string, std::vector<std::vector<int>>> levelMap;

public:
    explicit LevelMap(string levelMapPath);

    void Render(sf::RenderWindow *window) override;
};


#endif //CA3_LEVELMAP_H
