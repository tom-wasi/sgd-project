#include "Enemy.hpp"

const float Enemy::xTravel = Game::WIDTH/4;

Enemy::Enemy(const char* textureSheet, float x, float y) :
    GameObject(textureSheet, x, y, 15, 15, 2.0f), xStart(x) {
        movementSpeed = 100.0f;
}

void Enemy::update() {
    move();
    GameObject::update();
}

void Enemy::move() {
    x += direction * movementSpeed * Game::deltaTime;

    // substracting the actual width of texture since origin of the object is at top left
	const float right_limit = (xStart + Enemy::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;
	const float left_limit = (xStart - Enemy::xTravel) - GameObject::textureWidth * GameObject::textureUpscale;


	if (x >= right_limit) {
		x = right_limit;
		direction = -1;
	}
	else if (x <= left_limit) {
		x = left_limit;
		direction = 1;

	}
}

void Enemy::render() {
    GameObject::render();
}