#ifndef DRAGONKIN_H
#define DRAGONKIN_H

#include "Monster.h"

class Dragonkin : public Monster {
  private:
    int baseFireAttack;
  public:
    Dragonkin(bool);
    void attack(Player*) override;
    void fireAttack(Player*);
};

Dragonkin::Dragonkin(bool b):Monster(b){
  baseFireAttack=4;
  type="Dragonkin";
}

void Dragonkin::attack(Player *p){
  p -> receiveDamage(baseAttack+baseFireAttack);
}

#endif