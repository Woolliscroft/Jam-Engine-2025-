#include "Engine.hpp"
#include <SDL.h>
#include <iostream>

void Engine::Run() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
