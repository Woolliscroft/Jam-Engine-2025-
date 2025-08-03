
#include "SceneObject.hpp"
#include "Window.hpp"

SceneObject::SceneObject(SDL_Texture* texture, int x, int y, int w, int h)
    : Entity(texture, x, y, w, h) {}

void SceneObject::Update() {
    // probs dont need - unless i make fires/lights animation - NOT HAPPENING
}

void SceneObject::Render() {
    SDL_RenderCopy(Window::GetRenderer(), texture, &srcRect, &destRect);
}
