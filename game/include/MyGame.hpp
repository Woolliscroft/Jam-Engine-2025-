#pragma once
#include <SDL.h>

#include "Engine.hpp"
#include "ScreenManager.hpp"
#include "TextureLoader.hpp"

// use MyGame to inherit Enginenamespace and Game from that class - kinda clunky but reccommended by The Cherno
class MyGame : public Engine::Game {
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;

    void SetScreen(const std::string& name);

private:
    ScreenManager screenManager; //manage the screens, needs to be created here to work in MyGame.cpp
};