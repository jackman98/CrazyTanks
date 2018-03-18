#ifndef WORLD_H
#define WORLD_H
#include <thread>
#include "render.h"
#include "input.h"
#include "logic.h"
#include "ai.h"
#include "gamemanager.h"

using namespace std;

class World
{

    Render render;
    Input input;
    Logic logic;
    EnemyTankAI ai;

    GameManager *m;

    void buildField();
    void generateEnemyTanks(int countOfTanks);
    bool checkNeighboringCells(int x, int y, string symbol, int radius = 2);

public:
    World();
    void start();
};

#endif // WORLD_H
