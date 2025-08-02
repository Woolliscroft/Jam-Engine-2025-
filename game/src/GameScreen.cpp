#include "GameScreen.hpp"
#include "CharacterObject.hpp"
#include "EnemyObject.hpp"
#include "Window.hpp"
#include "ResourceManager.hpp"
#include "MyGame.hpp" 

GameScreen::GameScreen(MyGame* g) : game(g), player(nullptr) {}

void GameScreen::Init() {
    // ResourceManager for Files
    SDL_Texture* playerTex = ResourceManager::GetTexture("player");
    SDL_Texture* enemyTex = ResourceManager::GetTexture("enemy");
    
    // Initialise Character Objects
    player = new CharacterObject(playerTex, 100, 100, 32, 32);
    enemy = new EnemyObject(enemyTex, 400, 100, 32, 32);
    enemy->SetTarget(player);
}

void GameScreen::Update() {
    if (player) {
        player->Update();
    }
    if {
        (enemy) enemy->Update();
    }
}

void GameScreen::Render() {
    SDL_SetRenderDrawColor(Window::GetRenderer(), 0, 255, 0, 255);
    SDL_RenderClear(Window::GetRenderer());

    if (player) player->Render();
    if (enemy) enemy->Render();

    SDL_RenderPresent(Window::GetRenderer());
}

void GameScreen::HandleInput(const Uint8* keys) {
    if (keys[SDL_SCANCODE_T]) {
        game->SetScreen("TitleScreen");
    }

    if (player) player->HandleInput(keys);
}
