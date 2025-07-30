#pragma once
#include <SDL.h>  
#include <iostream>

class Screen {
public:
	// all screens must implement these methods
	virtual ~Screen() = default; 

	virtual void HandleEvent(const SDL_Event& e) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
};
