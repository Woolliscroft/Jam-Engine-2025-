#pragma once
#include "TextureLoader.hpp"
#include "Screen.hpp"

class MyGame; // more forward declarations bc of weird error message? could be silly idk - check back
class GameScreen;  


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