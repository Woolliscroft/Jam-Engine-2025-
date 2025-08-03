#pragma once

#include "Screen.hpp"  // <-- This is crucial
#include "CharacterObject.hpp"
#include "EnemyObject.hpp"
#include "SceneObject.hpp"

class MyGame;  // Forward declaration

class GameScreen : public Screen {
public:
    GameScreen(MyGame* g);

    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;

private:
    MyGame* game;
    CharacterObject* player = nullptr;
    EnemyObject* enemy = nullptr;
    SceneObject* tile = nullptr;
};
