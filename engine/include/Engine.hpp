#pragma once
#include <SDL.h>
#include <memory>

namespace Engine { 
    // cant initialise game - made abstract (i think?)
    class Game {
    public:
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void HandleInput(const Uint8* keys) = 0;

        // Add this line to enable event handling
        virtual void HandleEvent(const SDL_Event& event) {}

        virtual ~Game() = default;
    };

    class Engine {
    public:
        Engine();
        ~Engine();

        void SetGame(std::unique_ptr<Game> gameInstance);
        void Start();
    private:
        void Stop();
        std::unique_ptr<Game> game;
        bool quit = false;
    };
}
