#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <memory>

#include "Engine.hpp"
#include "MyGame.hpp"

MyGame* gMyGame = nullptr; 
/*DON'T TOUCH ^ */

//====== This is the Engine & Game Launcher ======/

int main() {
    Engine::Engine engine;

    /*Can Change this to whatever class you want: literally just enter class name */
    auto game = std::make_unique<MyGame>(); 
    /* Otherwise just leave Game.hpp/cpp and expand from there following documentation provided*/

    gMyGame = game.get(); // global pointer to Game 

    engine.SetGame(std::move(game));
    engine.Start();

    return 0;
}
/*DON'T TOUCH ^ */