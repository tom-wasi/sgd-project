#pragma once
#include "GameObject.hpp"
#include "TextureService.hpp"

class Projectile : public GameObject {
    private:
        float xDelta, yDelta;
        static SDL_Texture* texture;
    public:
        Projectile(float x, float y, float xDelta, float yDelta);
        void update();
        static SDL_Texture* getTexture();
};