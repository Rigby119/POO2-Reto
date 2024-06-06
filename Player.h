#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Monster;

class Player{
  protected:
    string name, type;
    int level, hp, maxHP;
    float exp, baseAttack;
  public:
    Player();
    Player(string);
    string getName(){return name;}
    string getClass(){return type;}
    int getHP(){return hp;}
    int getMaxHP(){return maxHP;}
    virtual void showInfo(){cout << name;}
    bool isAlive(){if (hp<=0) return false; else return true;}
    void setHP(int newHp){hp=newHp;}
    virtual void heal(Player*) {cout << "";}
    virtual void receiveDamage(int dmg){hp-=dmg; if(hp<0){hp=0;}}
    virtual void attack(Monster*);
};

#include "Monster.h"

Player::Player(string nm){
  name=nm;
  level=0;
  hp=30;
  maxHP=30;
  exp=0.0;
  baseAttack=10;
};

void Player::attack(Monster* m){
  m->receiveDamage(baseAttack);
}

#endif