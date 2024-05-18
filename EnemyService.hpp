#pragma once

#include "Enemy.hpp"
#include "Game.hpp"
#include <vector>

class EnemyService {
public:
    EnemyService(int totalEnemies);
    ~EnemyService();

    void init();
    //void update();
    void render();

private:
    static int maxInXAxis;
    int enemyCount, totalEnemies;

    std::vector<Enemy*> enemies;

};