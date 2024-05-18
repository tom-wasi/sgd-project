#pragma once
#include "GameObject.hpp"
#include "Input.hpp"
class Player :
    public GameObject
{
public:
    Player(const char* texturesheet, float x, float y);

    void update();
    int getHeight() const { return height; }

private:
    int height;
    float movementSpeed;
    void move(float xInput);
};