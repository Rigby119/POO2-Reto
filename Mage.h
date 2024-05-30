#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

using namespace std;

class Mage : public Player {
  private:
    string element;
    int mana;
  public:
    Mage(string nm);
    Mage(string e, string nm);
    void increaseExp(float NewExp);
    void heal(Player *p);
    void showInfo();
    void updateAttributes();
};

Mage::Mage(string nm) : Player(nm){
  int res = rand()%2;
  if (res == 1){
    element="Light";
  } else{
    element="Dark";
  }
  mana=100;
  type="Mage";
}

Mage::Mage(string e, string nm) : Player(nm){
  element=e;
  mana=100;
  type="Mage";
}

void Mage::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "ID: " << ID << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Element: " << element << endl;
  cout << "Mana: " << mana << endl;
};

void Mage::updateAttributes(){
  hp+=5;
  baseAttack+=0.1;
  mana+=15;
}

void Mage::heal(Player *p){
  p -> setHP(getHP()/2+getHP());
}

void Mage::increaseExp(float NewExp){
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