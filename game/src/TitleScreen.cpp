#include <SDL.h>

#include "TitleScreen.hpp"
#include "GameScreen.hpp"
#include "MyGame.hpp"
#include "Window.hpp"

TitleScreen::TitleScreen(MyGame* g) : game(g) {}

void TitleScreen::Init() {}

void TitleScreen::Update() {}

void TitleScreen::Render() {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 0, 255, 255); //set background colour
    SDL_RenderClear(Window::GetRenderer()); //render stuff
}

void TitleScreen::HandleInput(const Uint8* keys) { // make it use a mouse and not button - add mouse input
    if (keys[SDL_SCANCODE_E]) {
        game->SetScreen("GameScreen");
    }
}