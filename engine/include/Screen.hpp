#pragma once
#include <SDL.h>

class Screen {
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void HandleInput(const Uint8* keys) = 0;
    virtual void HandleEvent(const SDL_Event& event) {};

    virtual ~Screen() = default;
};
