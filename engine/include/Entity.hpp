#pragma once
#include <SDL.h>


// - abstract!
class Entity {
public:
    Entity(SDL_Texture* texture, int x, int y, int w, int h);
    virtual ~Entity() = default;  // Add this if missing

    virtual void Update();  // mark virtual if you haven't
    virtual void Render();

    const SDL_Rect& GetRect() const;

protected: // protected so classes can use it that aren't in Enitity and have changes
    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};