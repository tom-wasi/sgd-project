#include "Weapon.hpp"

Weapon::Weapon() {

    this->maxProjectiles = 100;

}

Weapon::Weapon(int maxProjectiles) {

    this->maxProjectiles = maxProjectiles;
    
}

bool Weapon::Shoot(float x, float y, float xDelta, float yDelta) {

    if(projectiles.size() < maxProjectiles){
    Projectile *p = new Projectile(x, y, xDelta, yDelta);
    projectiles.push_back(p);
    return true;
    } else {
        return false;
    }

}