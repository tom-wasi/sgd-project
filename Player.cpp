#include "Player.hpp"

Player::Player(const char* texturesheet, float x, float y) :GameObject("Player", texturesheet, x, y, 14, 14, 3.0f) {
	
    // movement speed of the player
    movementSpeed = 400.0f;

    // record the time when the weapon was last fired
    lastWeaponFire = SDL_GetTicks();

    weapon = Weapon(200);

    // register the player with the game
    GameObject::RegisterGameObject(this);
}

int Player::weaponFreezeTime = 1000; //ms


void Player::update() {
    float xInput = 0;

    if (Input::GetKeyDown(SDL_SCANCODE_A) || Input::GetKeyDown(SDL_SCANCODE_LEFT)) {
        xInput = -1;
        //std::cout << "A detected" << std::endl;
    }

    if (Input::GetKeyDown(SDL_SCANCODE_D) || Input::GetKeyDown(SDL_SCANCODE_RIGHT)) {
        xInput = 1;
        //std::cout << "D detected" << std::endl;
    }

    if (Input::GetKeyDown(SDL_SCANCODE_SPACE) && (SDL_GetTicks() > lastWeaponFire + Player::weaponFreezeTime)) {
        weapon.Shoot(x+(textureWidth * textureUpscale)/4.0f, y, 0.0f, -100.0f);
        lastWeaponFire = SDL_GetTicks();
        //std::cout << "SPACE detected" << std::endl;
    }

    move(xInput);
    GameObject::update();
}

void Player::move(float xInput) {

    // update the player's position based on the input direction and the movement speed
    x += xInput * movementSpeed * Game::deltaTime;

    // define the right border of the game area
    const float rightBorder = Game::WIDTH - textureWidth * textureUpscale;

    // if the player has moved beyond the right border, reset to the right border
    if (x >= rightBorder) {
        x = rightBorder;
    } 
    // if the player has moved beyond the left border, reset to the left border
    else if (x <= 0) {
        x = 0;
    }
}