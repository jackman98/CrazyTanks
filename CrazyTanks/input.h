#ifndef INPUT_H
#define INPUT_H
#include <conio.h>
#include <thread>
#include <chrono>
#include "gameproccespart.h"

class Input : public GameProccesPart
{
public:
    Input();
    void process();
};

#endif // INPUT_H
