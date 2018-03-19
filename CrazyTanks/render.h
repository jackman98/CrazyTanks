#ifndef RENDER_H
#define RENDER_H
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "gameproccespart.h"

using namespace std;

class Render : public GameProccesPart
{
public:
    Render();
    void process();
};

#endif // RENDER_H
