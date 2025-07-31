#include <SDL.h>

#include "GameScreen.hpp"
#include "TitleScreen.hpp"
#include "MyGame.hpp"
#include "Window.hpp"
#include "ResourceManager.hpp"


GameScreen::GameScreen(MyGame* g) : game(g) {}

void GameScreen::Init() {
    playerTex = ResourceManager::GetTexture("player");
    dstRect.x = 100;
    dstRect.y = 100;
    dstRect.w = 64;
    dstRect.h = 64;
}

void GameScreen::Update() {}

void GameScreen::Render() {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 255, 0, 255); // background color
    SDL_RenderClear(Window::GetRenderer());

    // Draw the texture
    SDL_RenderCopy(Window::GetRenderer(), playerTex, nullptr, &dstRect);

    SDL_RenderPresent(Window::GetRenderer()); // Present everything to the screen
}

void GameScreen::HandleInput(const Uint8* keys) {
    if (keys[SDL_SCANCODE_T]) {
        game->SetScreen("TitleScreen");
    }

    if (keys[SDL_SCANCODE_W]) dstRect.y -= 4;
    if (keys[SDL_SCANCODE_S]) dstRect.y += 4;
    if (keys[SDL_SCANCODE_A]) dstRect.x -= 4;
    if (keys[SDL_SCANCODE_D]) dstRect.x += 4;
}

