#include <SDL.h>
#include "Entity.hpp"

Entity::Entity(SDL_Texture* texture, int x, int y, int w, int h)
    : texture(texture)
{
    srcRect = { 0, 0, w, h };
    destRect = { x, y, w, h };
}

void Entity::Update() {
    // Default implementation (can be empty)
}

void Entity::Render() {
    // Default implementation (can be empty)
}

const SDL_Rect& Entity::GetRect() const {
    return destRect;
}
