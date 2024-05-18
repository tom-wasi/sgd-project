#pragma once
#include "GameObject.hpp"
#include "Input.hpp"
#include "Weapon.hpp"

class Player :
    public GameObject
{
public:
    Player(const char* texturesheet, float x, float y);
    Weapon weapon;
    void update();
    void render();
    int getHeight() const { return height; }

private:
    int height;
    float movementSpeed;
    void move(float xInput);
};