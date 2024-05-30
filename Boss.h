#ifndef BOSS_H
#define BOSS_H

#include "Player.h"
#include "Dungeon.h"

class Boss : public Monster{
  private:
    string title;
    int turns;
  public:
    Boss(int, int, int, string);
    void monsterAttack(Player *p){p -> receiveDamage(attack);}
};

Boss::Boss(int h, int a, int t, string tt) : Monster(h,a){
  HP=h;
  attack=a;
  turns=t;
  title=tt;
}

#endif