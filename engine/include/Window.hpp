#pragma once
#include <SDL.h>
#include <iostream>

class Window {
public:
	static SDL_Window* GetWindow();
	static SDL_Renderer* GetRenderer(); //need this so Screen & Window know what im talking abt

	static bool Init();
	static void CleanUp();
private:
	static SDL_Window* window;
	static SDL_Renderer* renderer;
}