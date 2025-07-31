#include "MyGame.hpp"
#include "TitleScreen.hpp"
#include "GameScreen.hpp"
#include "ResourceManager.hpp"

void MyGame::SetScreen(const std::string& name) {
    screenManager.SetScreen(name);
}

void MyGame::Init() {
    ResourceManager::LoadTexture("player", "../assets/player.png");
    
    // Make Screens, and then set to TitleScreen
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
