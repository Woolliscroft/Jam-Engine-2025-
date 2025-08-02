#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "TextureLoader.hpp"
#include "Window.hpp"

// Texture Loading with stb_image.h because couldn't get SDL_image to work
SDL_Texture* TextureLoader::LoadTexture(const std::string& path) {
    int width, height, channels;
    unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);

    if (!pixels) {
        std::cerr << "stb_image error: " << stbi_failure_reason() << std::endl;
        return nullptr;
    }

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(
        pixels, width, height, 32, width * 4, SDL_PIXELFORMAT_RGBA32
    );

    if (!surface) {
        std::cerr << "Failed to create image: Check FilePath" << std::endl;
        stbi_image_free(pixels);
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::GetRenderer(), surface);
    SDL_FreeSurface(surface);
    stbi_image_free(pixels);

    return texture;
}