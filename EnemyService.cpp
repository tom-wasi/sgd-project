#include "EnemyService.hpp"

int EnemyService::maxInXAxis = 7;

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
        if(countInCurrentLayer == EnemyService::maxInXAxis){
            currentLayer++;
            currentOffset = 0;
            countInCurrentLayer = 0;
        }

        int maxInCurrentLayer = EnemyService::maxInXAxis;

        if(currentLayer >= totalLayer){
            maxInCurrentLayer = (totalEnemies % EnemyService::maxInXAxis);
        }

        currentOffset++;
        const int xInit = (Game::WIDTH / 2 + (maxInCurrentLayer / 2.0f - currentOffset) * 42) + 9.5f;
        const int yInit = Game::HEIGHT / 2 + (currentLayer * 42);

        enemies.push_back(Enemy("src/assets/enemy.png", xInit, yInit));
        countInCurrentLayer++;
    }
    
}

void EnemyService::update() {

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].update();
    }

}

void EnemyService::render() {
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].render();
    }
    
}
