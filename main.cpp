#include "Game.hpp"

const int WIDTH = 640, HEIGHT = 480;

Game *game = nullptr;

int main(int argc, char* argv[]) {
	
	game = new Game();
	game->init("SGD_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
	Uint32 lastTicks = SDL_GetTicks();

	while(game->running()) {

		game->handleEvents();
		
		game->update();
		game->render();

	};

	game->clean();
	return 0;
}