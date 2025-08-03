#pragma once
#include "Entity.hpp"
#include <SDL.h>

class SceneObject : public Entity {
public:
    // Explicit constructor declaration matching your cpp definition
    SceneObject(SDL_Texture* texture, int x, int y, int w, int h);

    // Override virtual update and render methods
    virtual void Update() override;
    virtual void Render() override;

    SDL_Rect GetBounds() const {
        return destRect;
    }
};
