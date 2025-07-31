#include <SDL.h>

#include "GameScreen.hpp"
#include "TitleScreen.hpp"
#include "MyGame.hpp"
#include "Window.hpp"


GameScreen::GameScreen(MyGame* g) : game(g) {}

void GameScreen::Init() {}

void GameScreen::Update() {}

void GameScreen::Render() {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 255, 0, 255); // background colour
    SDL_RenderClear(Window::GetRenderer());
}

void GameScreen::HandleInput(const Uint8* keys) {
    if (keys[SDL_SCANCODE_T]) {
        game->SetScreen("TitleScreen");
    }
}
