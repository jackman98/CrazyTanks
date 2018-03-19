#ifndef TANK_H
#define TANK_H
#include <vector>
#include <cell.h>
#include "constants.h"

using namespace std;

enum Direction {///class
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
    bool checkingFreePlaceBeforeTank(vector<vector<Cell> > &field, Direction direction);

public:
    int x;
    int y;
    int health;
    int id;
    Direction direction;
    Type type;

    Tank(vector<vector<Cell> > &field, int x, int y, int id, Type type);
    void move(vector<vector<Cell> > &field, Direction direction);
    void paintTank(vector<vector<Cell> > &field, Direction d);
    void shot();
};

#endif // TANK_H
