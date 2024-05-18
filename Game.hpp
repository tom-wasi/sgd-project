#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "TextureManager.hpp"
#include "SDL2/SDL_image.h"

class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

		void handleEvents();
		void update();
		void render();
		void clean();

		bool running() { return isRunning; }
		
		const static int WIDTH, HEIGHT;

		static SDL_Renderer* renderer;
		static SDL_Event event;
		static float deltaTime;
	private:
		bool isRunning;
		SDL_Window* window;
		
};