#include "Window.hpp"

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;

bool Window::Init() {
	bool result = true;
	int windowHeight = 600;
	int windowWidth = 800;
	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (!window) {
		std::cerr << "Failed to create a window: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		std::cerr << "Failed to create renderer" << SDL_GetError() << std::endl;
		result = false;
	}
	return result;
}

void Window::CleanUp() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	if (window) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}

SDL_Window* Window::GetWindow() {
	return window;
}

SDL_Renderer* Window::GetRenderer() {
	return renderer;
}