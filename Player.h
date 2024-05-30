#ifndef PLAYER_H
#define PLAYER_H

#include "Dungeon.h"

#include <string>
#include <iostream>

using namespace std;

class Player {
  protected:
    string name, ID, type;
    int level, hp;
    float exp, baseAttack;
  public:
    Player(string nm);
    void attack(Monster *m){m -> receiveDamage(baseAttack);};
    int getHP(){return hp;};
    void setHP(int NewHp){hp=NewHp;};
    void receiveDamage(int dmg){hp=hp-dmg;}
};

Player::Player(string nm){
  ID=to_string(rand());
  name=nm;
  level=0;
  hp=30;
  exp=0.0;
  baseAttack=1.0;
};

#endif