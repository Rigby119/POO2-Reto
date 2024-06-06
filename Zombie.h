#ifndef GRUNT_H
#define GRUNT_H

#include "Monster.h"

class Zombie : public Monster {
  private:
    bool resurrected;
  public:
    Zombie(bool b);
    void attack(Player* p) override;
};

Zombie::Zombie(bool b):Monster(b){
  if (b){
    resurrected=true;
  } else {
    resurrected=false;
  }
  type="Zombie";
}

void Zombie::attack(Player *p){
  if (resurrected){
    p->receiveDamage(baseAttack);
  } else{
    p->receiveDamage(baseAttack/2);
  }
}

#endif