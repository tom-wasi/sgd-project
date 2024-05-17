#include "Game.hpp"

Game *game = nullptr;

int main(int argc, char* args[])
{
  game = new Game();

  game->init("SGD_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

  Uint32 lastTicks = SDL_GetTicks();

	float deltaTime = 0;
	while(game->running()) {

		// Wait until 16ms has elapsed since last frame
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 16)) {
		deltaTime = (SDL_GetTicks() - lastTicks )/1000.0f;

		// max deltaTime value must be clamped
		if (deltaTime > 0.05f)
		{
			deltaTime = 0.05f;
		}
		game->handleEvents();

		game->update(deltaTime);
		game->render();
		lastTicks = SDL_GetTicks();
    }

	};

  game->clean();

  return 0;
}