#pragma once

#include "Entity.hpp"
#include <SDL2/SDL.h>

class CharacterObject : public Entity {
public:
    CharacterObject(SDL_Texture* texture, int x, int y, int w, int h);

    void Update() override;
    void Render() override;
    void HandleInput(const Uint8* keys);

    void SetCollision(bool enabled, Entity* other);
    SDL_Rect GetBounds() const;

    // Accessors for position
    SDL_Rect GetDestRect() const;
    void SetDestRect(const SDL_Rect& rect);

    // Collision state
    bool collisionEnabled = false;
    Entity* collidingWith = nullptr;

    // For collision rollback
    SDL_Rect previousPos;
};
