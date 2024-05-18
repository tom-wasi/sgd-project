#include "GameObject.hpp"

GameObject::GameObject(const char* texturesheet, float x, float y, int textureWidth, int textureHeight, float textureUpscale) 
    : x(x), y(y), textureWidth(textureWidth), textureHeight(textureHeight), textureUpscale(textureUpscale) {
    objectTexture = TextureManager::LoadTexture(texturesheet);
    if (objectTexture == nullptr) {
        std::cerr << "Failed to load texture: " << texturesheet << std::endl;
    } else {
        std::cout << "GameObject created with texture: " << texturesheet << std::endl;
    }
	this->x = x;
	this->y = y;
	this->textureWidth = textureWidth;
	this->textureHeight = textureHeight;
	this->textureUpscale = textureUpscale;
}

void GameObject::update() {
    srcRect.w = textureWidth;
    srcRect.h = textureHeight;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.w = static_cast<int>(textureWidth * textureUpscale);
    destRect.h = static_cast<int>(textureHeight * textureUpscale);
    destRect.x = static_cast<int>(x);
    destRect.y = static_cast<int>(y);

   }

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}