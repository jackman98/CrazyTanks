#include "render.h"
#include <thread>
#include <chrono>
#include <iomanip>
//#include <windows.h>

Render::Render()
{
    m = &GameManager::instance();
}

//
//The use of this function instead of "system("cls");" gives a better and optimized rendering
//
//void setcur(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

void Render::process()
{
    while (!m->stopGame) {
    system("cls");
//    setcur(0,0);
    string str;

    cout << setw(m->width / 2 + 6) << "CRAZY TANKS" << endl;
    cout << "Score: " << m->score << " | Health: " << m->tank->health << " | Time : " << m->timeInGame << endl;

    for (size_t i = 0; i < m->field.size(); i++) {
        for (size_t j = 0; j < m->field.at(i).size(); j++) {
            str += m->field.at(i).at(j).getCell();
        }
        str += "\n";
    }
    cout << str;
    this_thread::sleep_for(chrono::milliseconds(20));
    }
    if (m->victory)
        cout << "YOU WINNER!!!";
    else
        cout << "GAME OVER!!!";
}



