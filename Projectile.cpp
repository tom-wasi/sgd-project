#include "Projectile.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

SDL_Texture* Projectile::texture = nullptr;

SDL_Texture* Projectile::getTexture() {

    // if the texture has not been loaded yet, load it
    if (!Projectile::texture) {
        Projectile::texture = TextureService::LoadTexture("src/assets/bolt.png");
    }

    return Projectile::texture;
}


Projectile::Projectile(float x, float y, float xDelta, float yDelta, ProjectileType type) :
    GameObject("Projectile", Projectile::getTexture(), x, y) {

    this->type = type;

    // set the movement deltas for the projectile
    this->xDelta = xDelta;
    this->yDelta = yDelta;

    // collision box for the projectile
    GameObject::SetCollisionBox(textureWidth * textureUpscale, textureHeight * textureUpscale);
    GameObject::RegisterGameObject(this);
}

void Projectile::Collided(GameObject* gameObject) {
    Enemy* enemy = dynamic_cast<Enemy*>(gameObject);
    if (type == ProjectileType::PLAYER_PROJECTILE) {
        if (enemy != NULL) {
            enemy->Destroy();
        }
        GameObject::DestroyGameObject((GameObject*)this);
        }

    GameObject::DestroyGameObject(gameObject);
    GameObject::DestroyGameObject(this);
}


void Projectile::update() {

    // update the position of the projectile based 
    // on the movement deltas and the time since the last game frame
    x += xDelta * Game::deltaTime;
    y += yDelta * Game::deltaTime;

    if (y<0 || y>Game::HEIGHT + 10.0f) {
        GameObject::DestroyGameObject((GameObject*)this);
    }

    GameObject::update();
}
