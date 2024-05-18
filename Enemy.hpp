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
        short int horizontalMovementCounter = 0;
        const float xStart;
        static const float xTravel;
        static const int horizontalMovementTriggerCount;
        void move();
};