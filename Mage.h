#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player{
  private:
    string element;
  public:
    Mage();
    Mage(string);
    Mage(string, string);
    void showInfo() override;
    void heal(Player*) override;
    void increaseExp(float);
    void updateAttributes();
    void attack(Monster*) override;
};

Mage::Mage(string nm):Player(nm){
  type="Mage";
  int res=rand()%2;
  if (res==1){
    element="Light";
  } else{
    element="Dark";
  }
}

Mage::Mage(string nm, string e):Player(nm){
  type="Mage";
  element=e;
}

void Mage::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << "/" << maxHP << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Element: " << element << endl;
}

void Mage::heal(Player* p){
  int cura = (p->getMaxHP()-p->getHP())/2;
  p -> setHP(cura+p->getHP());
}

void Mage::increaseExp(float newExp){
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

void Mage::updateAttributes(){
  maxHP+=5;
  hp=maxHP;
  baseAttack+=1;
}

void Mage::attack(Monster* m){
  bool alive = m->isAlive();
  string mType = m->getRace();
  if (element=="Dark" && mType=="Dragonkin"){
    m->receiveDamage(baseAttack+5);
  } else if (element=="Light" && mType=="Zombie"){
    m->receiveDamage(baseAttack+5);
  } else{
    m->receiveDamage(baseAttack);
  }
  if (alive && !m->isAlive()){
    increaseExp(50);
  }
}

#endif