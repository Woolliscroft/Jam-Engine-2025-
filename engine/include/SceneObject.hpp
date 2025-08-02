#pragma once
#include "Entity.hpp"

class SceneObject : public Entity {
public:
    SceneObject(SDL_Texture* texture, int x, int y, int w, int h);

    void Update() override;
    void Render() override;
};
