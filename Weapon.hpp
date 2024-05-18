#pragma once
#include <vector>
#include "Projectile.hpp"

class Weapon {

    public:
        Weapon();
        void Update();
        void Render();

        void Shoot(float x, float y, float xDelta, float yDelta);

    private:
        std::vector<Projectile> projectiles;
};