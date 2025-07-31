#pragma once
#include <string>
#include <unordered_map>
#include <SDL.h>

class ResourceManager {
public:
    static SDL_Texture* LoadTexture(const std::string& id, const std::string& filepath);
    static SDL_Texture* GetTexture(const std::string& id);
    static bool HasTexture(const std::string& id);
    static void Clear();

private:
    static std::unordered_map<std::string, SDL_Texture*> textures;
};
