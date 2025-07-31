#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <memory>

#include "Engine.hpp"
#include "MyGame.hpp"

MyGame* gMyGame = nullptr; // global pointer

int main() {
    Engine::Engine engine;

    auto game = std::make_unique<MyGame>();
    gMyGame = game.get(); // global pointer to Game 

    engine.SetGame(std::move(game));
    engine.Start();

    return 0;
}
