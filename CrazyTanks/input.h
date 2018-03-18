#ifndef INPUT_H
#define INPUT_H
#include <conio.h>
#include "gamemanager.h"

class Input
{
    GameManager *m;
public:
    Input();
    void process();
};

#endif // INPUT_H
