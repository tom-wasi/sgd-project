#include "Weapon.hpp"

Weapon::Weapon() {

    this->maxProjectiles = 200;

}

Weapon::Weapon(int maxProjectiles) {

    this->maxProjectiles = maxProjectiles;

}

Weapon::Weapon(int maxProjectiles, Projectile::ProjectileType) {

    this->maxProjectiles = maxProjectiles;
    this->projectileType = projectileType;
}

bool Weapon::Shoot(float x, float y, float xDelta, float yDelta) {

    if(projectiles.size() < maxProjectiles){
    Projectile *p = new Projectile(x, y, xDelta, yDelta, projectileType);
    projectiles.push_back(p);
    return true;
    } else {
        return false;
    }

}