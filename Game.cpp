#include "Game.hpp"

Game::Game()
{

}

Game::~Game()
{

}


void Game::init(const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }


    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        std::cout << "Initialized SDL properly!" << std::endl;

        window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);

        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    } else {

        // If SDL doesn't initialize correctly, 
        // the bool will be checked in the main
        // class and the game won't be rendered
        isRunning = false;
    }
}

void Game::update() 
{
    count++;
    std::cout << count << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL quitted" << std::endl;

}

bool Game::running(){ return isRunning; }