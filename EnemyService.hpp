#pragma once

#include "Enemy.hpp"
#include "Game.hpp"
#include <vector>

class EnemyService {
public:
    static int enemyShootingChance;
    static float enemyProjectileSpeed;
    static int enemyShootingInterval;
    EnemyService(int totalEnemies);
    ~EnemyService();

    void init();
    void render();

private:
    static int maxInXAxis;
    int enemyCount, totalEnemies;

    std::vector<Enemy*> enemies;

};