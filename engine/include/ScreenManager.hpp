#pragma once
#include "Screen.hpp"
#include <memory>

/*Manage Switching Between Screens*/

class ScreenManager {
public:
	void SetScreen(std::unique_ptr<Screen> newScreen) {
		currentScreen = std::move(newScreen);
	}

	void HandleEvent(const SDL_Event& e) {
		if (currentScreen) {
			currentScreen->HandleEvent(e);
		}
	}

	void Update(float deltaTime) {
		if (currentScreen) {
			currentScreen->Update(deltaTime);
		}
	}

	void Render(SDL_Renderer* renderer) {
		if (currentScreen) {
			currentScreen->Render(renderer);
			SDL_RenderPresent(renderer); // actually render smth
		}
	}
private:
	std::unique_ptr<Screen> currentScreen;
};