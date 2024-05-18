#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Game.hpp"

class TextureService
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
};