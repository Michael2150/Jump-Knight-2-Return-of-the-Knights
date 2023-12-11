//
// Created by micha on 11/12/2023.
//

#ifndef CA3_PLAYER_ENTITY_H
#define CA3_PLAYER_ENTITY_H


#include "../ecm/Entity.h"
#include "Box2D/Dynamics/b2World.h"

class Player_Entity : public Entity {
private:
    b2World* world;

public:
    explicit Player_Entity(b2World* physics_world) {
        world = physics_world;
    }

    void Start() override;
};


#endif //CA3_PLAYER_ENTITY_H
