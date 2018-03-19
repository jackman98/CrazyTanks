#include "timer.h"

Timer::Timer()
{
}

void Timer::process()
{
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        m->timeInGame++;
    }
}
