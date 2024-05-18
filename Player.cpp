#include "Player.hpp"

Player::Player(const char* texturesheet, float x, float y) :GameObject(texturesheet, x, y) {
	movementSpeed = 400.0f;
}

void Player::update()
{
    for (int w = 10000000; w > 0; w--);

	 if (Input::GetKeyDown(SDL_SCANCODE_A)) {
		x -= movementSpeed * Game::deltaTime;
		std::cout << " A pressed" << std::endl;
	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_D)) {
		 x += movementSpeed * Game::deltaTime;
		 std::cout << " D pressed" << std::endl;
	 }

	 if (Input::GetKeyDown(SDL_SCANCODE_SPACE)) {
		 std::cout << " SPACE pressed" << std::endl;

	 }



	GameObject::update();
}