#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Input.hpp"

Player* playerObject;
GameObject* enemyObject;

Uint32 lastTicks;
int frame;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
float Game::deltaTime;

Game::Game()
{
    
}

Game::~Game() 
{

}


void Game::init(const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen)
{
   

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        lastTicks = SDL_GetTicks();
        std::cout << "Initialized SDL properly!" << std::endl;
        
        int flags = 0;
        if (fullscreen) {
           flags = SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);

        if (window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer created!" << std::endl;
        } else {
            std::cout << SDL_GetError() << std::endl;
        }
        

        isRunning = true;

        playerObject = new Player("src/player.png", 0, 0);
        enemyObject = new GameObject("src/enemy.png", 100, 20);

    } else {

        // If SDL doesn't initialize correctly, 
        // the bool will be checked in the main
        // class and the game won't be rendered
        isRunning = false;
    }
}

bool done = false;

void Game::handleEvents()
{
    Input::SetKeystate();

    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update() 
{
    // Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 16))
		;
	deltaTime = (SDL_GetTicks() - lastTicks)/1000.0f;
	lastTicks = SDL_GetTicks();
	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

    if(playerObject == nullptr && enemyObject == nullptr) {
    std::cout << "Player and enemy are nullptr!" << std::endl;
    } else {
	playerObject->update();
	enemyObject->update();
    } 
    frame++;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    playerObject->render();
    enemyObject->render();

    SDL_RenderPresent(renderer);

    
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
