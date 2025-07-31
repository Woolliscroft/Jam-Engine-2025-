#include "Engine.hpp"
#include "Window.hpp"
#include "ScreenManager.hpp"
#include <SDL.h>
#include <iostream>
#include <chrono>
#include <thread>

class TestScreen : public Screen {
public:
    void HandleEvent(const SDL_Event& e) override {
        if (e.type == SDL_QUIT) {
            running = false;
        }
    }

    void Update(float deltaTime) override {
        // update game logic here
    }

    void Render(SDL_Renderer* renderer) override {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        // draw your objects here
    }

    static bool running;
};
bool TestScreen::running = true;

void Engine::Run() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        return;
    }

    if (!Window::Init()) {
        std::cerr << "Window initialization failed\n";
        return;
    }

    SDL_Renderer* renderer = Window::GetRenderer();
    ScreenManager screenManager;
    screenManager.SetScreen(std::make_unique<TestScreen>());

    auto lastTime = std::chrono::high_resolution_clock::now();

    while (TestScreen::running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            screenManager.HandleEvent(e);
        }

        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta = currentTime - lastTime;
        lastTime = currentTime;

        screenManager.Update(delta.count());
        screenManager.Render(renderer);

        SDL_Delay(16); // ~60 fps
    }

    Window::CleanUp();
    SDL_Quit();
}
