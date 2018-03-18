#ifndef RENDER_H
#define RENDER_H
#include <iostream>
#include <vector>
#include "gamemanager.h"

using namespace std;

class Render
{
    GameManager *m;
public:
    Render();
    void process();
};

#endif // RENDER_H
