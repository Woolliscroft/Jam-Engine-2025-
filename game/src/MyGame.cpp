#include "MyGame.hpp"
#include "TitleScreen.hpp"
#include "GameScreen.hpp"
#include "ResourceManager.hpp"

void MyGame::SetScreen(const std::string& name) {
    screenManager.SetScreen(name);
}

void MyGame::Init() {
    // asset loading done here so it only is loaded once but can be used in multiple game screens, i think thats how it SHOULD work
    ResourceManager::LoadTexture("player", "../assets/player.png");
    ResourceManager::LoadTexture("enemy", "../assets/enemy.png");
    ResourceManager::LoadTexture("tile", "../assets/Tile.png");
    ResourceManager::LoadTexture("playgame", "../assets/startgamebutton.jpg");
    ResourceManager::LoadTexture("background", "../assets/starterimage.png");
    
    // Make Screens, and then set to TitleScreen (add button switching for screens)
    screenManager.RegisterScreen("TitleScreen", new TitleScreen(this));
    screenManager.RegisterScreen("GameScreen", new GameScreen(this));
    SetScreen("TitleScreen");
}

void MyGame::Update() {
    screenManager.Update();
}

void MyGame::Render() {
    screenManager.Render();
}

void MyGame::HandleInput(const Uint8* keys) {
    screenManager.HandleInput(keys);
}

void MyGame::HandleEvent(const SDL_Event& event) {
    screenManager.HandleEvent(event);
}
