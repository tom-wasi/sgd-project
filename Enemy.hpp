#pragma once
#include "GameObject.hpp"

class Weapon;
class Enemy : public GameObject {

    public :
        int enemyPosX, enemyPosY;
        Weapon* weapon;
        bool canShoot = false;

        Enemy(const char *textureSheet, float x, float y);

        void Update();
        void Render();

        void Destroy();
        void TryShooting();

    private :
        float movementSpeed;
        short int direction = 1;
        short int horizontalMovementCounter = 0;
        const float xStart;
        static const float xTravel;
        static const int horizontalMovementTriggerCount;
        void Move();
        Uint16 lastWeaponFire;
};