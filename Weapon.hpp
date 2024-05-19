#pragma once
#include <vector>
#include "Projectile.hpp"

class Weapon {

    public:
        Weapon();
        Weapon(int maxProjectiles);
        Weapon(int maxProjectiles, Projectile::ProjectileType projectileType);

        bool Shoot(float x, float y, float xDelta, float yDelta);

    private:
        std::vector<Projectile*> projectiles;
        int maxProjectiles;
        Projectile::ProjectileType projectileType;
};