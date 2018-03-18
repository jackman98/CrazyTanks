#include "ai.h"

EnemyTankAI::EnemyTankAI()
{
    m = &GameManager::instance();
}

void EnemyTankAI::process()
{
    while (!m->stopGame){
        shoting();
        this_thread::sleep_for(chrono::milliseconds(rand() % 300 + 200));
        moving();
    }

}

Direction EnemyTankAI::getRandomDirection()
{
    switch (rand()% 4) {
    case 0:
        return UP;
        break;
    case 1:
        return DOWN;
        break;
    case 2:
        return RIGHT;
        break;
    case 3:
        return LEFT;
        break;
    default:
        break;
    }
}

void EnemyTankAI::moving()
{
    for(int i = 0; i < m->enemyTanks.size(); ++i) {
        m->enemyTanks[i]->move(m->field, getRandomDirection());
    }
}

void EnemyTankAI::shoting()
{
    for(int i = 0; i < m->enemyTanks.size(); ++i) {
        bool isNeedShot = static_cast<bool>(rand() % 2);
        if (isNeedShot) {
            Bullet *b = new Bullet(m->enemyTanks[i]->x, m->enemyTanks[i]->y, m->enemyTanks[i]->type, m->enemyTanks[i]->direction);
            m->enemyBullets.push_back(b);
        }
    }
}
