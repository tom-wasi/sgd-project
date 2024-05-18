#pragma once
#include "GameObject.hpp"

class Enemy : public GameObject {

    public :
        Enemy(const char* textureSheet, float x, float y);

        void update();
        void render();

    private :
        float movementSpeed;
        short int direction = 1;
        const float xStart;
        static const float xTravel;
        void move();
};