#include "Game.hpp"

const int WIDTH = 640, HEIGHT = 480;

Game *game = nullptr;

int main(int argc, char* argv[]) {
    game = new Game();
    game->init("SGD_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::WIDTH, Game::HEIGHT, false);
    
    if (!game->running()) {
        std::cerr << "Game failed to start" << std::endl;
        return -1;
    }

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}