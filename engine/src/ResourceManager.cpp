#include "ResourceManager.hpp"
#include "TextureLoader.hpp"
#include <iostream>

std::unordered_map<std::string, SDL_Texture*> ResourceManager::textures;

SDL_Texture* ResourceManager::LoadTexture(const std::string& id, const std::string& filepath) {
    if (HasTexture(id)) {
        std::cerr << "Warning: Texture ID '" << id << "' already loaded.\n";
        return textures[id];
    }

    SDL_Texture* texture = TextureLoader::LoadTexture(filepath);
    if (texture) {
        textures[id] = texture;
    } else {
        std::cerr << "Failed to load texture at path: " << filepath << std::endl;
    }
    return texture;
}

SDL_Texture* ResourceManager::GetTexture(const std::string& id) {
    if (HasTexture(id)) {
        return textures[id];
    }
    std::cerr << "Warning: Texture ID '" << id << "' not found.\n";
    return nullptr;
}

bool ResourceManager::HasTexture(const std::string& id) {
    return textures.find(id) != textures.end();
}

void ResourceManager::Clear() {
    for (auto& pair : textures) {
        SDL_DestroyTexture(pair.second);
    }
    textures.clear();
}
