#include "bulletaction.h"

BulletAction::BulletAction()
{
    m = &GameManager::instance();
}

//processing the intersection with tanks and walls
bool BulletAction::checkIntersection(Bullet &b, int x, int y) {
    if (m->field[y][x].getCell() == "$") {
        b.isShotMade = false;
        return true;
    }
    //If on the way at the bullet the enemy tank and the bullet of the main tank
    if (m->field[y][x].getCell() == "@" && b.type == MAIN) {
        for (size_t i = 0; i < m->enemyTanks.size(); ++i) {
            if (checkTank(b, m->enemyTanks[i], x, y)) {
                return true;
            }
        }
    }

    //If on the way at the bullet the main tank and the bullet of the enemy tank
    if (m->field[y][x].getCell() == "#" && b.type == ENEMY) {
        if (checkTank(b, m->tank, x, y)) {
            return true;
        }
    }

    //If on the way at the bullet the enemy tank and the bullet of the enemy tank
    //do not replace the tank with a bullet
    if (!(m->field[y][x].getCell() == "@" && b.type == ENEMY))
        m->field[y][x].setCell("*");

    return false;
}

bool BulletAction::checkTank(Bullet &b, Tank *t, int x, int y)
{
    //check in which tank to take health
    if (t->id == m->field[y][x].id) {
        //if the health are zero, we erase the tank from the field
        if (--(t->health) == 0) {
            x = t->x;
            y = t->y;
            m->field[y][x].setCell(" ");
            m->field[y - 1][x].setCell(" ");
            m->field[y + 1][x].setCell(" ");
            m->field[y][x - 1].setCell(" ");
            m->field[y][x + 1].setCell(" ");
            m->field[y - 1][x - 1].setCell(" ");
            m->field[y + 1][x - 1].setCell(" ");
            m->field[y + 1][x + 1].setCell(" ");
            m->field[y - 1][x + 1].setCell(" ");
        }
        b.isShotMade = false;
        return true;
    }

    return false;
}

void BulletAction::shot(Bullet &b)
{
    //bullet flight
    if (m->field[b.y][b.x].getCell() == "*")
        m->field[b.y][b.x].setCell(" ");

    switch (b.direction) {
    case LEFT:
        if (checkIntersection(b, b.x - 1, b.y))
            return;
        --b.x;
        break;
    case RIGHT:
        if (checkIntersection(b, b.x + 1, b.y))
            return;
        ++b.x;
        break;
    case UP:
        if (checkIntersection(b, b.x, b.y - 1))
            return;
        --b.y;
        break;
    case DOWN:
        if (checkIntersection(b, b.x, b.y + 1))
            return;
        ++b.y;
        break;
    }
}
