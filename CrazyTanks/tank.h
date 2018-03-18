#ifndef TANK_H
#define TANK_H
#include <vector>
#include <cell.h>

using namespace std;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

enum Type {
    MAIN,
    ENEMY
};

class Tank
{
public:
    int x;
    int y;
    int health = 2;
    int id;
    Direction direction;
    Type type;

    Tank(vector<vector<Cell> > &field, int x, int y, int id, Type type);
    void move(vector<vector<Cell> > &field,  Direction direction);
    void paintMainTank(vector<vector<Cell> > &field, Direction d);
    void paintEnemyTank(vector<vector<Cell> > &field, Direction d);
    void shot();
};

#endif // TANK_H
