#include "Player.hpp"

Player::Player(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y, 14, 14, 3.0f) {
	movementSpeed = 400.0f;
    height = 32;
}

void Player::update() {
    float xInput = 0;

    if (Input::GetKeyDown(SDL_SCANCODE_A) || Input::GetKeyDown(SDL_SCANCODE_LEFT)) {
        xInput = -1;
        std::cout << "A pressed" << std::endl;
    }

    if (Input::GetKeyDown(SDL_SCANCODE_D) || Input::GetKeyDown(SDL_SCANCODE_RIGHT)) {
        xInput = 1;
        std::cout << "D pressed" << std::endl;
    }

    if (Input::GetKeyDown(SDL_SCANCODE_SPACE)) {
        std::cout << "SPACE pressed" << std::endl;
    }

    move(xInput);
    GameObject::update();
}

void Player::move(float xInput) {
    x += xInput * movementSpeed * Game::deltaTime;

    const float rightBorder = Game::WIDTH - textureWidth * textureUpscale;

    if (x >= rightBorder) {
        x = rightBorder;
    } else if (x <= 0) {
        x = 0;
    }
}
