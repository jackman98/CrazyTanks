#ifndef TIMER_H
#define TIMER_H
#include "gameproccespart.h"
#include <thread>
#include <chrono>

class Timer : public GameProccesPart
{
public:
    Timer();

    void process();
};

#endif // TIMER_H
