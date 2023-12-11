//
// Created by micha on 05/12/2023.
//

#ifndef CA3_LEVELMAP_H
#define CA3_LEVELMAP_H

#include <string>
#include <map>
#include <vector>
#include "../ecm/Entity.h"
#include "TileSet.h"

using std::string;

class LevelMap: public Entity {
private:
    string levelMapPath;
    std::map<string, TileSet> layers;

public:
    explicit LevelMap(string levelMapPath, shared_ptr<TileSet> sourceTileSet);

    void Render(sf::RenderWindow *window) override;

    TileSet * getLayer(string layerName);
};


#endif //CA3_LEVELMAP_H
