#include "Engine.hpp"

class MyGame : public Engine::Game {
public:
    void Init() override { /* ... */ }
    void Update() override { /* ... */ }
    void Render() override { /* ... */ }
    void HandleInput(const Uint8* keys) override { /* ... */ }
};

int main() {
    Engine::Engine engine;
    auto game = std::make_unique<MyGame>();
    engine.SetGame(std::move(game));
    engine.Start();
    return 0;
}
