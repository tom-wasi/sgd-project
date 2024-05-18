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
    int getHeight() const { return height; }

private:
    int height;
    float movementSpeed;
    void move(float xInput);
    Uint16 lastWeaponFire;
    static int weaponFreezeTime;
};