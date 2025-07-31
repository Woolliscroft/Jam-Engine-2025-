#include "MyGame.hpp"
#include "MyGame.hpp"
#include "TitleScreen.hpp"
#include "GameScreen.hpp"


void MyGame::SetScreen(const std::string& name) {
    screenManager.SetScreen(name);
}

void MyGame::Init() {
    RegisterScreen<TitleScreen>("TitleScreen");
    RegisterScreen<GameScreen>("GameScreen");
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
