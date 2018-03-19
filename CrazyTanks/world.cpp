#include "world.h"

void World::buildField()
{
    //generation new field
    m->field.clear();
    for (int i = 0; i < HEIGHT; i++) {
        vector<Cell> row;
        for (int j = 0; j < WIDTH; j++) {
            Cell block(" ");
            row.push_back(block);
        }
        m->field.push_back(row);
    }
    //generation field boundaries
    for (int i = 0; i < HEIGHT; i++) {
        m->field.at(i).at(0).setCell("$");
        m->field.at(i).at(WIDTH - 1).setCell("$");
    }
    for (int i = 0; i < WIDTH; i++) {
        m->field.at(0).at(i).setCell("$");
        m->field.at(HEIGHT - 1).at(i).setCell("$");
    }

    //generation walls
    for (int i = 0;  i < 20; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int widthBlock = rand() % 3 + 1;
        int heightBlock = rand() % 3 + 1;
        m->field.at(y).at(x).setCell("$");

        for (int j = 1; j <= widthBlock; ++j)
            if (x + j < WIDTH)
                m->field.at(y).at(x + j).setCell("$");
        for (int j = 1; j <= heightBlock; ++j)
            if (y + j < HEIGHT)
                m->field.at(y + j).at(x).setCell("$");
    }

    //generation and addition of the main tank to the field
    m->tank = new Tank(m->field, WIDTH / 2 , HEIGHT - 3, 0, Type::MAIN);
    m->tank->health = MY_HEALTH;

    //generation and addition of the enemy tans to the field
    generateEnemyTanks(COUNT_OF_ENEMY_TANKS);
}

void World::generateEnemyTanks(int countOfTanks)
{
    int i = 0;
    while (i != countOfTanks) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        //        check the place for a new tank
        if (checkNeighboringCells(x, y, "$", 1) || checkNeighboringCells(x, y, "@", 3)) {
            //            if the place is occupied by a wall or near a tank, we continue and generate new coordinates
            continue;
        }
        m->enemyTank = new Tank(m->field, x, y, i + 1, Type::ENEMY);
        m->enemyTanks.push_back(m->enemyTank);
        ++i;
    }
}

//check the neighboring cells around the (x,y) in the presence of a symbol with a radius,
//if such a character was found returns true
bool World::checkNeighboringCells(int x, int y, string symbol, int radius)
{
    for (int offsetY = -1 * radius; offsetY <= 1 * radius; ++offsetY) {
        for (int offsetX = -1 * radius; offsetX <= 1 * radius; ++offsetX) {
            if ((offsetY == 0 && offsetX == 0) || (y + offsetY >= static_cast<int>(m->field.size())) ||
                    (y + offsetY < 0) || (x + offsetX >= m->field.at(0).size()) || (x + offsetX < 0)) {
                //                if we go beyond the boundaries of the field, we continue
                continue;
            }
            if (m->field.at(y + offsetY).at(x + offsetX).getCell() == symbol)
                return true;
        }
    }
    return false;
}

World::World()
{
    m = &GameManager::instance();
}

void World::startGame()
{
    buildField();

    //create threads
    thread renderThread(&Render::process, ref(render));
    renderThread.detach();

    thread logicThread(&Logic::process, ref(logic));
    logicThread.detach();

    thread aiThread(&EnemyTankAI::process, ref(ai));
    aiThread.detach();

    thread timeThread(&Timer::process, ref(timer));
    timeThread.detach();

    input.process();
}


