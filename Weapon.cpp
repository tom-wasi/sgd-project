#include "Weapon.hpp"

void Weapon::Shoot(float x, float y, float xDelta, float yDelta) {

    projectiles.push_back(Projectile(x, y, xDelta, yDelta));

}

void Weapon::Update() {

    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i].update();
    }

}

void Weapon::Render() {

    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i].render();
    }

}

Weapon::Weapon() {}