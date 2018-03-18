#include "bulletaction.h"

BulletAction::BulletAction()
{
    m = &GameManager::instance();
}

bool BulletAction::checkIntersection(Bullet &b, vector<Tank *> &enemyTanks, int x, int y) {
    if (m->field[y][x].getCell() == "$") {
        b.isShotMade = false;
        return true;
    }
    if ((m->field[y][x].getCell() == "@" && b.type == MAIN) || (m->field[y][x].getCell() == "#" && b.type == ENEMY)) {
        for (size_t i = 0; i < enemyTanks.size(); ++i) {
            if (enemyTanks[i]->id == m->field[y][x].id) {
                if (--(enemyTanks[i]->health) == 0) {
                    x = enemyTanks[i]->x;
                    y = enemyTanks[i]->y;
                    m->field[y][x].setCell(" ");
                    m->field[y - 1][x].setCell(" ");
                    m->field[y + 1][x].setCell(" ");
                    m->field[y][x - 1].setCell(" ");
                    m->field[y][x + 1].setCell(" ");
                    m->field[y - 1][x - 1].setCell(" ");
                    m->field[y + 1][x - 1].setCell(" ");
                    m->field[y + 1][x + 1].setCell(" ");
                    m->field[y - 1][x + 1].setCell(" ");
                    delete enemyTanks[i];
                    enemyTanks[i] = nullptr;
                    enemyTanks.erase(enemyTanks.begin() + i);
                    vector<Tank *>(enemyTanks).swap(enemyTanks);
                }
                b.isShotMade = false;
                return true;
            }
        }
    }
    if (!(m->field[y][x].getCell() == "@" && b.type == ENEMY))
        m->field[y][x].setCell("*");
    return false;
}

void BulletAction::shot(Bullet &b, vector<Tank *> &enemyTanks)
{
    if (m->field[b.y][b.x].getCell() == "*")
        m->field[b.y][b.x].setCell(" ");
    switch (b.direction) {
    case LEFT:
        if (checkIntersection(b, enemyTanks, b.x - 1, b.y))
            return;
        --b.x;
        break;
    case RIGHT:
        if (checkIntersection(b, enemyTanks, b.x + 1, b.y))
            return;
        ++b.x;
        break;
    case UP:
        if (checkIntersection(b, enemyTanks, b.x, b.y - 1))
            return;
        --b.y;
        break;
    case DOWN:
        if (checkIntersection(b, enemyTanks, b.x, b.y + 1))
            return;
        ++b.y;
        break;
    default:
        break;
    }
}
