//
// Created by micha on 11/12/2023.
//

#include "Player_Entity.h"
#include "../components/Player_Controller_cmp.h"
#include "../components/Player_Camera_cmp.h"
#include "../components/Player_Door_Check_cmp.h"

void Player_Entity::Start() {
    CreateComponent<Text_cmp>("Player Debug");
    CreateComponent<Player_Door_Check_cmp>();
    CreateComponent<Player_Controller_cmp>(world);
    CreateComponent<Player_Animator_cmp>();
    CreateComponent<Player_Camera_cmp>();

    getTransform()->setScale({3.0f, 3.0f});

    // I forgot this and it messed me uppppp for like 10mins!!!
    Entity::Start();
}
