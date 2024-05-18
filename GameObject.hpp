#pragma once
#include <SDL2/SDL.h>
#include "Game.hpp"

class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y);
	~GameObject();

	void update();
	void render();
protected:
	float x, y;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};