 #include <SDL.h>

#include "Engine.hpp"
#include "Window.hpp"

namespace Engine {

Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    Window::Init();
}

Engine::~Engine() {
    Stop();
    SDL_Quit();
}

void Engine::SetGame(std::unique_ptr<Game> gameInstance) {
    game = std::move(gameInstance);
}

void Engine::Start() {
    if (!game) return; 

    game->Init();
    const Uint8* keys = nullptr;

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

        SDL_RenderClear(Window::GetRenderer()); // clear previous renderer before rendering game again
        game->Render();
        SDL_RenderPresent(Window::GetRenderer()); //draw it again, once game gives more detail abt what to draw
        SDL_Delay(16);
    }
}

void Engine::Stop() {
    Window::OnCleanUp();
}

} // namespace Engine
