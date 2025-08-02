#pragma once
#include "Entity.hpp"

class CharacterObject : public Entity {
public:
    CharacterObject(SDL_Texture* texture, int x, int y, int w, int h);

    void Update() override; //methods to be filled in by user
    void Render() override;

    void HandleInput(const Uint8* keys);
};
