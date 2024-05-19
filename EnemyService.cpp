#include "EnemyService.hpp"
#include "Weapon.hpp"
#include "Projectile.hpp"

int EnemyService::maxInXAxis = 7;
int EnemyService::enemyShootingChance = 2;
int EnemyService::enemyShootingInterval = 200;
float EnemyService::enemyProjectileSpeed = 300.0f;


EnemyService::EnemyService(int totalEnemies){
    this->totalEnemies = this->enemyCount = totalEnemies;
}


void EnemyService::init(){
    int currentLayer = 0; 
    int countInCurrentLayer = 0; 
    int currentOffset = 0;
    int totalLayer = (int)(totalEnemies / EnemyService::maxInXAxis);

    
    for (int i = 0; i < totalEnemies; i++)
    {
        // if the current layer is full, move to the next layer
        if(countInCurrentLayer == EnemyService::maxInXAxis){
            currentLayer++;
            currentOffset = 0;
            countInCurrentLayer = 0;
        }

        // calculate the maximum number of enemies in the current layer
        int maxInCurrentLayer = EnemyService::maxInXAxis;
        if(currentLayer >= totalLayer){
            maxInCurrentLayer = (totalEnemies % EnemyService::maxInXAxis);
        }

        // calculate the initial position of the enemy
        currentOffset++;
        const int xInit = (Game::WIDTH / 2 + (maxInCurrentLayer / 2.0f - currentOffset) * 42) + 9.5f;
        const int yInit = 42 + (currentLayer * 42);

        // create a new enemy and add it to the list of enemies
        Enemy* enemy = new Enemy("src/assets/enemy.png", xInit, yInit);
        enemies.push_back(enemy);
        enemy->enemyPosX = countInCurrentLayer;
        enemy->enemyPosY = currentLayer;
        if (currentLayer == totalLayer) {
            enemy->canShoot = true;
        }
        countInCurrentLayer++;
    }
}


void EnemyService::render() {
    
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->render();
    }
}