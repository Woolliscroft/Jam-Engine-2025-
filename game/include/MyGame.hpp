#pragma once
#include "Engine.hpp"

class MyGame : public Engine::Game {
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;
};
