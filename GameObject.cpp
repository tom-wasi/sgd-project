#include "GameObject.hpp"
#include <algorithm>

std::vector<GameObject*> GameObject::gameObjects;
int GameObject::lastId = 0;

GameObject::GameObject(const char* name, const char* texturesheet, float x, float y, int textureWidth, int textureHeight, float textureUpscale) 
    : x(x), y(y), textureWidth(textureWidth), textureHeight(textureHeight), textureUpscale(textureUpscale) {
    
    objectTexture = TextureService::LoadTexture(texturesheet);
    if (objectTexture == nullptr) {
        std::cerr << "Failed to load texture: " << texturesheet << std::endl;
    } else {
        std::cout << "GameObject created with texture: " << texturesheet << std::endl;
    }
    
    this->x = x;
    this->y = y;
    this->name = (char*)name;
    this->textureWidth = textureWidth;
    this->textureHeight = textureHeight;
    this->textureUpscale = textureUpscale;
}

GameObject::GameObject(const char* name, SDL_Texture* texture, float x, float y, int textureWidth, int textureHeight, float textureUpscale) {

    objectTexture = texture;
    this->x = x;
    this->y = y;
    this->name = (char*)name;
    this->textureWidth = textureWidth;
    this->textureHeight = textureHeight;
    this->textureUpscale = textureUpscale;
}

void GameObject::update() {

    // update the source and destination rectangles
    srcRect.w = textureWidth;
    srcRect.h = textureHeight;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.w = static_cast<int>(textureWidth * textureUpscale);
    destRect.h = static_cast<int>(textureHeight * textureUpscale);
    destRect.x = static_cast<int>(x);
    destRect.y = static_cast<int>(y);

    // if the game object has a collision box, update it and check for collisions
    if(hasCollision) {
        UpdateCollisionBox();
        CheckForCollision();
    }
}

void GameObject::SetCollisionBox(int w, int h) {
    hasCollision = true;
    collisionBox.x = this->x;
    collisionBox.y = this->y;
    collisionBox.w = w;
    collisionBox.h = h;
}

void GameObject::UpdateCollisionBox() {
    collisionBox.x = this->x;
    collisionBox.y = this->y;
}

void GameObject::CheckForCollision() {
    for (int i = 0; i < gameObjects.size(); i++) {
        if (gameObjects.at(i)->hasCollision && gameObjects.at(i) != this)  {
            if (Collision::AABB(collisionBox, gameObjects.at(i)->collisionBox)) {
                gameObjects[i]->Collided(this);
            }
        }
    }
}

void GameObject::Collided(GameObject* gameObject) {}

void GameObject::render() {
    SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
    if (hasCollision) {
        SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Game::renderer, &collisionBox);
    }
}

int GameObject::RegisterGameObject(GameObject* gameObject) {
    gameObject->ID = ++lastId;
    gameObjects.push_back(gameObject);
    return gameObject->ID;
}

void GameObject::DestroyGameObject(GameObject* gameObject) {
    gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), gameObject), gameObjects.end());
    delete gameObject;
}

void GameObject::UpdateEvery() {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update();
    }
}

void GameObject::RenderEvery() {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->render();
    }
}

GameObject::~GameObject(){}