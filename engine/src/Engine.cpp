#include "Engine.hpp"

namespace Engine {

Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    // create window, renderer etc.
}

Engine::~Engine() {
    SDL_Quit();
}

void Engine::SetGame(std::unique_ptr<Game> gameInstance) {
    game = std::move(gameInstance);
}

void Engine::Start() {
    if (!game) return; // no game set

    game->Init();

    SDL_Event event;
    quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
        }

        const Uint8* keys = SDL_GetKeyboardState(NULL);
        game->HandleInput(keys);

        game->Update();
        game->Render();

        SDL_Delay(16); // approx 60 FPS
    }
}

void Engine::Stop() {
    quit = true;
}

} // namespace Engine
