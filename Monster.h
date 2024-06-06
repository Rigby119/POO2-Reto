#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Player;

class Monster{
  protected:
    int hp, baseAttack, index;
    bool boss;
    string type;
  public:
    Monster(bool);
    virtual ~Monster() {} // Destructor virtual
    virtual void attack(Player*) = 0;
    void showInfo();
    int getHP(){return hp;}
    bool isAlive(){if (hp<=0) return false; else return true;}
    string getRace(){return type;}
    bool getBoss(){return boss;}
    void setIndex(int i){index=i;}
    void receiveDamage(int);
    void kill();
};

#include "Player.h"

Monster::Monster(bool b){
  if (b){
    hp=50;
    baseAttack=10;
    boss=true;
  } else{
    hp=15;
    baseAttack=8;
    boss=false;
  }
}

void Monster::showInfo(){
  cout << "Health Points: " << hp << endl;
  cout << "Attack: " << baseAttack << endl;
  cout << "Race: " << type << endl;
}

void Monster::receiveDamage(int dmg){
  if (boss){
    hp-=dmg/2;
  } else{
    hp-=dmg;
  }
  if (hp<=0){hp=0;}
}

#endif