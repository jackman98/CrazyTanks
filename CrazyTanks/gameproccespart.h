#ifndef GAMEPROCCESPART_H
#define GAMEPROCCESPART_H
#include "gamemanager.h"

class GameProccesPart
{
protected:
    GameManager *m;

public:
    GameProccesPart();
    virtual void process() = 0;
};

#endif // GAMEPROCCESPART_H
