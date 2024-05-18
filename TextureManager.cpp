#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
    SDL_Surface* tempSurface = IMG_Load(filename);
    if (!tempSurface) {
        std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    if (!texture) {
        std::cout << "CreateTexture Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    SDL_FreeSurface(tempSurface);
    return texture;
}
