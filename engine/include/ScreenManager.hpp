#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include <functional>

#include "Screen.hpp"

class ScreenManager {
public:
    template<typename T, typename... Args>
    void RegisterScreen(const std::string& name, Args&&... args) {
        factories[name] = [=]() {
            return std::make_unique<T>(args...);
        };
    }

    void SetScreen(const std::string& name) {
        if (factories.count(name)) {
            currentScreen = factories[name]();
            currentScreen->Init();
        }
    }

    void Update() {  
        if (currentScreen) {
            currentScreen->Update();
        }
    }

    void Render() {
        if (currentScreen) {
            currentScreen->Render();
        }
    }

    void HandleInput(const Uint8* keys) {
        if (currentScreen) {
            currentScreen->HandleInput(keys);
        }
    }

private:
    std::unique_ptr<Screen> currentScreen;
    std::unordered_map<std::string, std::function<std::unique_ptr<Screen>()>> factories;
};
