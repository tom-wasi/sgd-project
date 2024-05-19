#pragma once
#include "GameObject.hpp"
#include "TextureService.hpp"

class Projectile : public GameObject {
    public:
        enum ProjectileType {
            PLAYER_PROJECTILE,
            ENEMY_PROJECTILE
        };

    private:
        ProjectileType type;
        float xDelta, yDelta;
        static SDL_Texture* texture;
        
    public:
        Projectile(float x, float y, float xDelta, float yDelta, ProjectileType type);
        void update();
        static SDL_Texture* getTexture();
        void Collided(GameObject* gameObject) override;
};