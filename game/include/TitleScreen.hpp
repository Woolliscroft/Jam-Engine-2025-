#pragma once
#include "Screen.hpp"
class MyGame;      // forward declaration
class GameScreen;  // forward


class TitleScreen : public Screen {
public:
    TitleScreen(MyGame* game);
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;
private:
    MyGame* game;
};
