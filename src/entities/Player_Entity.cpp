//
// Created by micha on 11/12/2023.
//

#include "Player_Entity.h"
#include "../components/Player_Controller_cmp.h"

void Player_Entity::Start() {
    CreateComponent<Player_Controller_cmp>(world);
    CreateComponent<Player_Animator_cmp>();
    getTransform().setScale({2.0f, 2.0f});

    // I forgot this and it messed me uppppp for like 10mins!!!
    Entity::Start();
}
