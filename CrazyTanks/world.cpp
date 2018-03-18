#include "world.h"
#include <future>

void World::buildField()
{
    m->field.clear();
    for (int i = 0; i < m->height; i++) {
        vector<Cell> row;
        for (int j = 0; j < m->width; j++) {
            Cell block(" ");
            row.push_back(block);
        }
        m->field.push_back(row);
    }
    for (int i = 0; i < m->height; i++) {
        m->field.at(i).at(0).setCell("$");
        m->field.at(i).at(m->width - 1).setCell("$");
    }
    for (int i = 0; i < m->width; i++) {
        m->field.at(0).at(i).setCell("$");
        m->field.at(m->height - 1).at(i).setCell("$");
    }

    for (int i = 0;  i < 20; ++i) {
        int x = rand() % m->width;
        int y = rand() % m->height;
        int widthBlock = rand() % 3 + 1;
        int heightBlock = rand() % 3 + 1;
        m->field.at(y).at(x).setCell("$");

        for (int j = 1; j <= widthBlock; ++j)
            if (x + j < m->width)
                m->field.at(y).at(x + j).setCell("$");
        for (int j = 1; j <= heightBlock; ++j)
            if (y + j < m->height)
                m->field.at(y + j).at(x).setCell("$");
    }

    m->tank = new Tank(m->field, m->width / 2 , m->height - 3, 0, Type::MAIN);
    m->tank->health = m->myHealth;

    generateEnemyTanks(m->countOfEnemyTanks);
}

void World::generateEnemyTanks(int countOfTanks)
{
    int i = 0;
    while (i != countOfTanks) {
        int x = rand() % m->width;
        int y = rand() % m->height;
        if (checkNeighboringCells(x, y, "$", 1) ||/* checkNeighboringCells(x, y, "@", 1) ||*/ checkNeighboringCells(x, y, "@", 3))
            continue;
        m->enemyTank = new Tank(m->field, x, y, i + 1, Type::ENEMY);
        m->enemyTanks.push_back(m->enemyTank);
        ++i;
    }
}

bool World::checkNeighboringCells(int x, int y, string symbol, int radius)
{
    for (int offsetY = -1 * radius; offsetY <= 1 * radius; ++offsetY) {
        for (int offsetX = -1 * radius; offsetX <= 1 * radius; ++offsetX) {
            if ((offsetY == 0 && offsetX == 0) || (y + offsetY >= static_cast<int>(m->field.size())) ||
                    (y + offsetY < 0) || (x + offsetX >= m->field.at(0).size()) || (x + offsetX < 0))
                continue;
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

void World::start()
{
    buildField();

    thread ren(&Render::process, ref(render));
    ren.detach();
    thread log(&Logic::process, ref(logic));
    log.detach();
    thread aiThread(&EnemyTankAI::process, ref(ai));
    aiThread.detach();

    input.process();
}


