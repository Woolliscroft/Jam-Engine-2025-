#pragma once
#include <SDL2/SDL.h>
#include <string>

class TextureLoader {
public:
    static SDL_Texture* LoadTexture(const std::string& path);
};