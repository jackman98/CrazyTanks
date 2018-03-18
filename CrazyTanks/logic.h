#ifndef LOGIC_H
#define LOGIC_H
#include "gamemanager.h"
#include "bulletaction.h"
#include <thread>
#include <chrono>

class Logic
{
    GameManager *m;
public:
    Logic();
    void process();
};

#endif // LOGIC_H
