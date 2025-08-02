#pragma once

#include "Screen.hpp"
#include "CharacterObject.hpp" 
#include "EnemyObject.hpp"


class MyGame; // forward declaring otherwise its kinda beefy and had some error; apparently this fixes it -check back later

class GameScreen : public Screen {
public:
    GameScreen(MyGame* game);  
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;

private:
    MyGame* game;

    CharacterObject* player = nullptr;

    EnemyObject* enemy = nullptr;
};
