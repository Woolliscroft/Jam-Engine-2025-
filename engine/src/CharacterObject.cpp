#include "CharacterObject.hpp"
#include "Window.hpp"

CharacterObject::CharacterObject(SDL_Texture* texture, int x, int y, int w, int h)
    : Entity(texture, x, y, w, h) {}

void CharacterObject::Update() {
    // You could put animation or state logic here
}

void CharacterObject::Render() {
    SDL_RenderCopy(Window::GetRenderer(), texture, &srcRect, &destRect);
}

void CharacterObject::HandleInput(const Uint8* keys) {
    const int speed = 4;

    if (keys[SDL_SCANCODE_W]) destRect.y -= speed;
    if (keys[SDL_SCANCODE_S]) destRect.y += speed;
    if (keys[SDL_SCANCODE_A]) destRect.x -= speed;
    if (keys[SDL_SCANCODE_D]) destRect.x += speed;
}
