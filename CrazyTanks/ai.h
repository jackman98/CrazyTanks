#ifndef AI_H
#define AI_H
#include "tank.h"
#include "gameproccespart.h"
#include <thread>

class EnemyTankAI : public GameProccesPart
{
    Direction getRandomDirection();
    void moving();
    void shoting();

public:
    EnemyTankAI();
    void process();
};

#endif // AI_H
