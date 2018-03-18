#include "input.h"
#include "bullet.h"
#include <future>

Input::Input()
{
    m = &GameManager::instance();
}

void Input::process()
{
    while (!m->stopGame) {
        if (_kbhit()) {
            switch (_getch()) {
            case 72:
                m->tank->move(m->field, UP);
                break;
            case 80:
                m->tank->move(m->field, DOWN);
                break;
            case 75:
                m->tank->move(m->field, LEFT);
                break;
            case 77:
                m->tank->move(m->field, RIGHT);
                break;
            case 32: {
                Bullet *b = new Bullet (m->tank->x, m->tank->y, m->tank->type, m->tank->direction);
                m->myBullets.push_back(b);
                break;
            }
            default:
                break;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(20));
    }
}
