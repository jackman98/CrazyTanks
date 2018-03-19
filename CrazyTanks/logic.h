#ifndef LOGIC_H
#define LOGIC_H
#include "gameproccespart.h"
#include "bulletaction.h"
#include <thread>
#include <chrono>

class Logic : public GameProccesPart
{
public:
    Logic();
    void process();
};

#endif // LOGIC_H
