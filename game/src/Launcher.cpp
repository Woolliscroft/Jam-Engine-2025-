#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <memory>

#include "Engine.hpp"
#include "MyGame.hpp"

// Personal Directory:
/* 
	cd “C:\Users\arunw\OneDrive - St Albans School\Documents\GMTK Jam 2025” 
*/

int main() {
    Engine::Engine engine;
    auto game = std::make_unique<MyGame>();
    engine.SetGame(std::move(game));
    engine.Start();
    return 0;
}
