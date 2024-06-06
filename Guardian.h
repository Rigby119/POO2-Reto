#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "Player.h"

class Guardian : public Player{
  private:
    float dp;
  public:
    Guardian(string);
    void showInfo();
    void updateAttributes();
    void increaseExp(float);
    void receiveDamage(int dmg){hp-=(dmg-dp);};
    void attack(Monster*);
};

Guardian::Guardian(string nm) : Player(nm){
  dp=2;
  hp+=5;
  maxHP+=5;
  type="Guardian";
}

void Guardian::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << "/" << maxHP << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Defense Points: " << dp << endl;
}

void Guardian::increaseExp(float newExp){
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

void Guardian::updateAttributes(){
  maxHP+=10;
  hp=maxHP;
  baseAttack+=1;
}

void Guardian::attack(Monster* m){
  bool alive = m->isAlive();
  m->receiveDamage(baseAttack);
  if (alive && !m->isAlive()){
    increaseExp(50);
  }
}

#endif