#pragma once

#include <SDL2/SDL.h>
#include "Game.hpp"
#include "SDL2/SDL_image.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	
	GameObject(SDL_Texture* texture, float x, float y, int textureWidth = 16, int textureHeight = 16, float textureUpscale = 1.0f);
	
	~GameObject();

	void update();
	void render();
protected:
	float x, y, textureUpscale;
    int textureWidth, textureHeight;

private:
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
};