#ifndef SOLDIER_H
#define SOLDIER_H

#include "Player.h"

using namespace std;

class Soldier : public Player {
  private:
    string weapon;
    float attackBoost;
  public:
    Soldier(string nm);
    Soldier(string w, string nm);
    void showInfo();
    void updateAttributes();
    void increaseExp(float NewExp);
    float attack();
};

Soldier::Soldier(string nm) : Player(nm){
  int res = rand()%2;
  if (res == 1){
    weapon="Longsword";
  } else{
    weapon="Mace";
  }
  attackBoost=0.5;
  baseAttack+=attackBoost;
  type="Soldier";
}

Soldier::Soldier(string w, string nm) : Player(nm){
  weapon=w;
  attackBoost=0.5;
  baseAttack+=attackBoost;
  type="Soldier";
}

void Soldier::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "ID: " << ID << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Weapon: " << weapon << endl;
  cout << "Attack Boost: " << attackBoost << endl;
};

void Soldier::updateAttributes(){
  hp+=5;
  baseAttack+=0.2;
  attackBoost+=0.1;
}

void Soldier::increaseExp(float NewExp){
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

float Soldier::attack(){
  return baseAttack+attackBoost;
}

#endif