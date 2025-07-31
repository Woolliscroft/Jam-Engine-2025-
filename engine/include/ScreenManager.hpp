#pragma once
#include <memory>
#include <unordered_map>
#include <string>

#include "Screen.hpp"

class ScreenManager {
public:
    // Make a Screen, using the Construcot
    void RegisterScreen(const std::string& name, Screen* screen) {
        screens[name] = std::unique_ptr<Screen>(screen);
    }

    // Set the screen using its name
    void SetScreen(const std::string& name) {
        if (screens.count(name)) {
            currentScreen = screens[name].get();
            currentScreen->Init();
        }
    }

    void Update() { // update current screen
        if (currentScreen) {
            currentScreen->Update();
        }
    }

    void Render() {
        if (currentScreen) {
            currentScreen->Render();
        }
    }

    void HandleInput(const Uint8* keys) { //checking input on the screen
        if (currentScreen) {
            currentScreen->HandleInput(keys);
        }
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Screen>> screens;
    Screen* currentScreen = nullptr;
};
