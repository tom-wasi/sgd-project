#include "Projectile.hpp"

SDL_Texture* Projectile::texture = nullptr;

SDL_Texture* Projectile::getTexture() {

    if (!Projectile::texture) {
        Projectile::texture = TextureService::LoadTexture("src/assets/bolt.png");
    }
    return Projectile::texture;

}

Projectile::Projectile(float x, float y, float xDelta, float yDelta) :
    GameObject(Projectile::getTexture(), x, y) {

    this->xDelta = xDelta;
    this->yDelta = yDelta;

}

void Projectile::update() {

    x += xDelta * Game::deltaTime;
    y += yDelta * Game::deltaTime;
    GameObject::update();

}
