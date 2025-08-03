#pragma once
#include <SDL.h>
#include "Screen.hpp"
#include "MyGame.hpp"
#include "SceneObject.hpp"

class TitleScreen : public Screen {
public:
    TitleScreen(MyGame* g);
    ~TitleScreen();

    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;
    void HandleEvent(const SDL_Event& event) override;

private:
    MyGame* game;
    SDL_Texture* playButtonTex = nullptr;
    SDL_Rect playButtonRect;
    SDL_Texture* backgroundTex;  // holds the background image

};
