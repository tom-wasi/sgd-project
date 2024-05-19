#include "Enemy.hpp"
#include "Weapon.hpp"
#include "EnemyService.hpp"

// The maximum distance the enemy can travel horizontally
const float Enemy::xTravel = Game::WIDTH/4;

// The number of times the enemy moves horizontally before it moves down
const int Enemy::horizontalMovementTriggerCount = 3;

// Constructor for the Enemy class
Enemy::Enemy(const char* textureSheet, float x, float y) :
    GameObject("Enemy", textureSheet, x, y, 15, 15, 2.0f), xStart(x) {
        movementSpeed = 100.0f; // the speed at which the enemy moves
        GameObject::SetCollisionBox(textureHeight * textureUpscale, textureWidth * textureUpscale); // Setting the collision box for the enemy
        GameObject::RegisterGameObject(this); 
        weapon = new Weapon(100, Projectile::ProjectileType::ENEMY_PROJECTILE);
        lastWeaponFire = 0;
}


void Enemy::Update() {
    Move(); 
    GameObject::update();
    if (canShoot && SDL_GetTicks() > lastWeaponFire + EnemyService::enemyShootingInterval) {
            TryShooting();
    }
} 


void Enemy::Move() {
    x += direction * movementSpeed * Game::deltaTime;

    // calculate the right and left limits for the enemy's movement
	const float right_limit = (xStart + Enemy::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;
	const float left_limit = (xStart - Enemy::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;

    // If the enemy has reached the right limit, change direction to left
	if (x >= right_limit) {
		x = right_limit;
		direction = -1;
	}
    // If the enemy has reached the left limit, change direction to right
	else if (x <= left_limit) {
		x = left_limit;
		direction = 1;
        horizontalMovementCounter++;
	}

    // move the enemy down after a certain number of horizontal movements
    if (horizontalMovementCounter >= Enemy::horizontalMovementTriggerCount) {
		y += textureHeight*textureUpscale;
		horizontalMovementCounter = 0;
	}
}

void Enemy::Destroy()
{
    hasCollision = false;
    GameObject::DestroyGameObject(this);
}

void Enemy::TryShooting()
{
    int rng = rand() % 2;
    if (rng < EnemyService::enemyShootingChance) {
        weapon->Shoot(x, y + (textureHeight * textureUpscale) + 1.0, 0.0f, EnemyService::enemyProjectileSpeed);
    }
    
    lastWeaponFire = SDL_GetTicks();
}

void Enemy::Render() {
    GameObject::render();
}