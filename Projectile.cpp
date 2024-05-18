#include "Projectile.hpp"

SDL_Texture* Projectile::texture = nullptr;

SDL_Texture* Projectile::getTexture() {

    // if the texture has not been loaded yet, load it
    if (!Projectile::texture) {
        Projectile::texture = TextureService::LoadTexture("src/assets/bolt.png");
    }

    return Projectile::texture;
}


Projectile::Projectile(float x, float y, float xDelta, float yDelta) :
    GameObject("Projectile", Projectile::getTexture(), x, y) {

    // set the movement deltas for the projectile
    this->xDelta = xDelta;
    this->yDelta = yDelta;

    // collision box for the projectile
    GameObject::SetCollisionBox(textureWidth * textureUpscale, textureHeight * textureUpscale);
    
    GameObject::RegisterGameObject(this);
}

void Projectile::Collided(GameObject* gameObject) {

    GameObject::DestroyGameObject(gameObject);
    GameObject::DestroyGameObject(this);
}


void Projectile::update() {

    // update the position of the projectile based 
    // on the movement deltas and the time since the last game frame
    x += xDelta * Game::deltaTime;
    y += yDelta * Game::deltaTime;

    GameObject::update();
}
