#include "TitleScreen.hpp"
#include "GameScreen.hpp"
#include "Window.hpp"
#include "ResourceManager.hpp"

TitleScreen::TitleScreen(MyGame* g) : game(g) {}

TitleScreen::~TitleScreen() {
    // We assume ResourceManager manages textures, so no SDL_DestroyTexture here
}

void TitleScreen::Init() {
    backgroundTex = ResourceManager::GetTexture("background");
    if (!backgroundTex) {
        SDL_Log("Failed to load background texture!");
    }

    playButtonTex = ResourceManager::GetTexture("playgame");

    int btnW = 200, btnH = 80;
    int winW = 800, winH = 600;

    // Position play button center screen
    playButtonRect = { (winW - btnW) / 2, (winH - btnH) / 2, btnW, btnH };
}



void TitleScreen::Update() {
}

void TitleScreen::Render() {
    SDL_Renderer* renderer = Window::GetRenderer();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Clear with black
    SDL_RenderClear(renderer);

    if (backgroundTex) {
        SDL_RenderCopy(renderer, backgroundTex, nullptr, nullptr);  // draw full screen
    } else {
        SDL_Log("backgroundTex is nullptr in Render!");
    }

    if (playButtonTex) {
        SDL_RenderCopy(renderer, playButtonTex, nullptr, &playButtonRect);
    }

    SDL_RenderPresent(renderer);

}


void TitleScreen::HandleInput(const Uint8* keys) {
    // you can leave empty or handle keyboard here if you want
}

void TitleScreen::HandleEvent(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x = event.button.x;
        int y = event.button.y;
        if (x >= playButtonRect.x && x <= playButtonRect.x + playButtonRect.w &&
            y >= playButtonRect.y && y <= playButtonRect.y + playButtonRect.h) {
            game->SetScreen("GameScreen");
        }
    }
}


