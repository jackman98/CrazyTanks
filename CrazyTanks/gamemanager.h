#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <vector>
#include <iostream>
#include "bullet.h"

using namespace std;

class GameManager
{
public:
  static GameManager& instance()
  {
    static GameManager singleton;
    return singleton;
  }

  int score = 0;
  int timeInGame = 0;
  const int width = 78;
  const int height = 26;
  const int countOfEnemyTanks = 5;
  const int myHealth = 3;

  bool stopGame = false;
  bool victory;
  vector<Bullet *> myBullets;
  vector<Bullet *> enemyBullets;
  vector<Tank *> enemyTanks;
  vector<vector<Cell>> field;

  Tank *tank;
  Tank *enemyTank;
private:
  GameManager() {}
  ~GameManager() {}
  GameManager(const GameManager&);
  GameManager& operator=(const GameManager&);
};

#endif // GAMEMANAGER_H
