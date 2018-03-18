#ifndef AI_H
#define AI_H
#include "tank.h"
#include "gamemanager.h"
#include <thread>

class EnemyTankAI
{
    GameManager *m;

    Direction getRandomDirection();
    void moving();
    void shoting();

public:
    EnemyTankAI();
    void process();
};

#endif // AI_H
