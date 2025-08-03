#pragma once
#include "Entity.hpp"

class EnemyObject : public Entity {
public:
    EnemyObject(SDL_Texture* texture, int x, int y, int w, int h);

    void Update() override;
    void Render() override;

    void SetTarget(const Entity* t);  // Set it for like better user code

private:
    void Pathfinding(const Entity* target);
    const Entity* target = nullptr;  // Store the player here? this in game too tho idek
};