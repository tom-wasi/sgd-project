#pragma once
#include "GameObject.hpp"
#include "Input.hpp"
class Player :
    public GameObject
{
public:
    Player(const char* texturesheet, float x, float y);

    void update();
private:
    float movementSpeed;
};