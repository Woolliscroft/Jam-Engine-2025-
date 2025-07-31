 #include <SDL.h>

#include "Engine.hpp"
#include "Window.hpp"
#include "ResourceManager.hpp"

namespace Engine {
// Engine Constructor
Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    Window::Init();
}
// Engine Destructor (not correct term idk)
Engine::~Engine() {
    // Stop() is called in Start() after loop, so no need here unless forcibly stopping
    SDL_Quit();
}

void Engine::SetGame(std::unique_ptr<Game> gameInstance) {
    game = std::move(gameInstance);
}

void Engine::Start() {
    if (!game) return; 

    game->Init();
    SDL_Event event;
    quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        const Uint8* keys = SDL_GetKeyboardState(nullptr); 
        game->HandleInput(keys);
        game->Update();

        SDL_RenderClear(Window::GetRenderer());
        game->Render();
        SDL_RenderPresent(Window::GetRenderer());
        SDL_Delay(16);
    }

    // Cleanup resources before quitting
    ResourceManager::Clear();
    Stop();  // Calls Window::OnCleanUp()
}


void Engine::Stop() {
    Window::OnCleanUp();
}

} 
