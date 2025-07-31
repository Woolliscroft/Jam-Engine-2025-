#pragma once
#include "Engine.hpp"
#include "ScreenManager.hpp"

class MyGame : public Engine::Game {
public:
    void Init() override;
    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys) override;

    void SetScreen(const std::string& name);

    template<typename T>
    void RegisterScreen(const std::string& name) {
        screenManager.RegisterScreen<T>(name, this);
    }

private:
    ScreenManager screenManager;
};
