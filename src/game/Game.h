#ifndef CA3_GAME_H
#define CA3_GAME_H

#include "../scenes/Scene.h"

class MenuScene : public Scene {
public:
    explicit MenuScene(const string& LevelMapPath, bool requiresPlayer = true) : Scene(LevelMapPath, requiresPlayer) {}
    void Initialize() override;
    void setActive(bool isActive) override;
};

class Level1 : public Scene {
public:
    explicit Level1(const string& LevelMapPath, bool requiresPlayer = true) : Scene(LevelMapPath, requiresPlayer) {}
    void Initialize() override;
    void setActive(bool isActive) override;
};

class Level2 : public Scene {
public:
    explicit Level2(const string& LevelMapPath, bool requiresPlayer = true) : Scene(LevelMapPath, requiresPlayer) {}
    void Initialize() override;
    void setActive(bool isActive) override;
};

class EndScene : public Scene {
public:
    explicit EndScene(const string& LevelMapPath, bool requiresPlayer = true) : Scene(LevelMapPath, requiresPlayer) {}
    void Initialize() override;
    void setActive(bool isActive) override;
};

#endif //CA3_GAME_H
