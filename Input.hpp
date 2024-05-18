#pragma once
#include "SDL2/SDL.h"
#include <iostream>
class Input
{
public:
	static Uint8* keystate;

	static bool GetKeyDown(SDL_Scancode key);
	static void SetKeystate();
};