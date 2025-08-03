#include "EnemyObject.hpp"
#include "Window.hpp"

EnemyObject::EnemyObject(SDL_Texture* texture, int x, int y, int w, int h)
    : Entity(texture, x, y, w, h) {}

void EnemyObject::Update() {
    if (target) {
        Pathfinding(target);
    }
}

void EnemyObject::Render() {
    SDL_RenderCopy(Window::GetRenderer(), texture, &srcRect, &destRect);
}


void EnemyObject::SetTarget(const Entity* t) {
    target = t;
}

void EnemyObject::Pathfinding(const Entity* target) {
    SDL_Rect playerPos = target->GetRect(); //should be stored as a pointer

    if (destRect.x < playerPos.x) destRect.x += 1;
    else if (destRect.x > playerPos.x) destRect.x -= 1;

    if (destRect.y < playerPos.y) destRect.y += 1;
    else if (destRect.y > playerPos.y) destRect.y -= 1;
}