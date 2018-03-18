#include "bullet.h"

Bullet::Bullet(int x, int y, Type type, Direction d) : x(x), y(y), type(type), direction(d)
{
    isShotMade = true;

    switch (d) {
    case LEFT:
           this->x--;
        break;
    case RIGHT:
            this->x++;
        break;
    case UP:
            this->y--;
        break;
    case DOWN:
            this->y++;
        break;
    default:
        break;
    }
}


