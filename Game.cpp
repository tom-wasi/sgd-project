#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Input.hpp"
#include "Enemy.hpp"
#include "EnemyService.hpp"

Player* playerObject;
EnemyService* enemyService;

Uint32 lastTicks;
int frame;

const int Game::WIDTH = 820;
const int Game::HEIGHT = 640;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
float Game::deltaTime;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xPosition, int yPosition, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
            isRunning = false;
            return;
        }

        lastTicks = SDL_GetTicks();

        int flags = 0;
        if (fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        window = SDL_CreateWindow(title, xPosition, yPosition, width, height, flags);
        if (!window) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            isRunning = false;
            return;
        }

        // SDL_RENDERER_ACCELERATED: this flag indicates that the renderer 
        // uses hardware acceleration. If you pass this flag,
        // you’re guaranteed not to get a software renderer

        //SDL_RENDERER_PRESENTVSYNC: This flag indicates that the renderer’s 
        //presentation is synchronized with the refresh rate2. When VSync 
        //is enabled, the video card stops the renderer from presenting a 
        //frame until a signal from the monitor indicating vertical 
        //synchronization arrives, which means it finished displaying the last frame
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        const int playerHeight = 64; 
        const int margin = 10;
        playerObject = new Player("src/assets/player.png", Game::WIDTH / 2, Game::HEIGHT - playerHeight - margin);
        enemyService = new EnemyService(35);
        enemyService->init();

        isRunning = true;
    } else {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        isRunning = false;
    }
}

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

void Game::update() {

    // Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), lastTicks + 16));
	deltaTime = (SDL_GetTicks() - lastTicks)/1000.0f;
	lastTicks = SDL_GetTicks();

	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

    GameObject::UpdateEvery();

    frame++;
    
}

void Game::render() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    GameObject::RenderEvery();

    SDL_RenderPresent(renderer);

}

void Game::clean(){

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}