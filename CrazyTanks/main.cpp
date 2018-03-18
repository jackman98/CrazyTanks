#include <iostream>
#include <vector>
#include <conio.h>
#include "cell.h"
#include "tank.h"
#include "bullet.h"
#include "bulletaction.h"
#include <thread>
#include <chrono>
#include <random>
#include <time.h>
#include <future>
#include "gamemanager.h"
#include "world.h"

using namespace std;

GameManager *m = &GameManager::instance();

void currentTime() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        ++m->timeInGame;
    }
}

int main()
{
    srand(time(0));

    auto a = async(launch::async, currentTime);

    World w;
    w.start();

    return 0;
}
