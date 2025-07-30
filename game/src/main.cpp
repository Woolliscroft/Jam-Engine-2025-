#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Engine.hpp"

int main() {
    Engine engine;
    engine.Run();
    return 0;
}
