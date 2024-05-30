#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "Player.h"

class Guardian : public Player {
  private:
    float dp;
  public:
    Guardian(string nm);
    void showInfo();
    void updateAttributes();
    void increaseExp(float NewExp);
    void receiveDamage(int dmg){hp=hp-dmg+dp;}
};

Guardian::Guardian(string nm) : Player(nm){
  dp=5;
  hp+=dp;
  type="Guardian";
}

void Guardian::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "ID: " << ID << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Defense Points: " << dp << endl;
};

void Guardian::updateAttributes(){
  dp+=5;
  hp+=10;
  baseAttack+=0.1;
}

void Guardian::increaseExp(float NewExp){
  float rate;
  if (level==0){rate=1;}
  else {rate=1/float(level);}
  exp+=NewExp/50*rate;
  while (exp>=1){
    level++;
    exp-=1;
    updateAttributes();
  }
}

#endif