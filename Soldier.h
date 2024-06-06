#ifndef SOLDIER_H
#define SOLDIER_H

#include "Player.h"

class Soldier : public Player{
  public:
    Soldier(string);
    void showInfo();
    void increaseExp(float);
    void updateAttributes();
    void attack(Monster*);
};

Soldier::Soldier(string nm):Player(nm){
  baseAttack=15;
  type="Soldier";
}

void Soldier::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << "/" << maxHP << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
};

void Soldier::increaseExp(float newExp){
  float rate;
  float points = newExp/50;
  while (true){
    if (level==0){
      rate=1.0;
    } else{
      rate=1.0/level;
    }
    exp+=points*rate;
    if (exp>=1){
      level++;
      updateAttributes();
      exp-=1;
      points=exp/rate;
      exp=0;
    } else{break;}
  }
}

void Soldier::updateAttributes(){
  maxHP+=5;
  hp=maxHP;
  baseAttack+=3;
}

void Soldier::attack(Monster* m){
  bool alive = m->isAlive();
  m->receiveDamage(baseAttack);
  if (alive && !m->isAlive()){
    increaseExp(50);
  }
}

#endif