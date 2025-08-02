#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <memory>

#include "Engine.hpp"
#include "MyGame.hpp"

/* FOR ME:
cd "C:\Users\arunw\OneDrive - St Albans School\Documents\GMTK Jam 2025"
cd build
*/

MyGame* gMyGame = nullptr; 
/*DON'T TOUCH ^ */

//====== This is the Engine & Game Launcher ======// probably done terrible but oh well

int main() {
    Engine::Engine engine;

    /*Can Change this to whatever class you want: literally just enter class name */
    auto game = std::make_unique<MyGame>(); 
    /* Otherwise just leave Game.hpp/cpp and expand from there following documentation provided (its not made yet - as of 02/08/25)*/

    gMyGame = game.get(); // global pointer to Game 

    engine.SetGame(std::move(game));
    engine.Start();

    return 0;
}
/*DON'T TOUCH ^ */