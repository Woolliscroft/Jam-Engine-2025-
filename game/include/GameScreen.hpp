#pragma once
#include "Screen.hpp"
class MyGame;

class GameScreen : public Screen {
public:
    GameScreen(MyGame* game);  
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;
private:
    MyGame* game;
};
