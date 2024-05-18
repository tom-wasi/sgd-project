#include "TextureService.hpp"

SDL_Texture* TextureService::LoadTexture(const char* filename) {

    SDL_Surface *imageSurface = IMG_Load(filename);
    if (!imageSurface) {
        std::cout << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    if (!texture) {
        std::cout << "CreateTexture Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    //std::cout << "Texture loaded successfully: " << filename << std::endl;
    return texture;

}