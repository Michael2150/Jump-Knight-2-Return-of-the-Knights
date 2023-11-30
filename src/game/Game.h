#ifndef CA3_GAME_H
#define CA3_GAME_H

#include "../scenes/Scene.h"

class MenuScene : public Scene {
public:
    void Initialize() override;
};

class Level1 : public Scene {
public:
    void Initialize() override;
};

class Level2 : public Scene {
public:
    void Initialize() override;
};

class Level3 : public Scene {
public:
    void Initialize() override;
};

class EndScene : public Scene {
public:
    void Initialize() override;
};

#endif //CA3_GAME_H
