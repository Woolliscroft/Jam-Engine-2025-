#pragma once
#include <SDL.h>
#include <iostream>

class Window {
public:
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer();
	static bool Init();
	static void OnCleanUp();

private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
};