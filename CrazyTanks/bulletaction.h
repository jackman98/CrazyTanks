#ifndef BULLETACTION_H
#define BULLETACTION_H
#include <vector>
#include "tank.h"
#include "gamemanager.h"
#include "bullet.h"

using namespace std;

class BulletAction
{
    GameManager *m;

public:
    BulletAction();

    bool checkIntersection(Bullet &b, vector<Tank *> &enemyTanks, int x, int y);
    void shot(Bullet &b, vector<Tank *> &enemyTanks);
};

#endif // BULLETACTION_H
