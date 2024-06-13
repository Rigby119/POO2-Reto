/*
 * Proyecto Shangri-La clase Zombie
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * La clase Zombie define a un objeto Zombie. Esta clase es hija de Monster y redefine
 * varios métodos de la clase Monster, incluyendo evidentemente el método pure virtual
 * que define a la clase Monster como abstracta. Esta clase tiene atributo de resurrected
 * que funciona similar al atributo boss de la madre.
*/

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Monster.h"

class Zombie : public Monster {
  private:
    bool resurrected;
  public:
    Zombie(bool b);
    void attack(Player* p);
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
    p->receiveDamage(baseAttack*2);
  } else{
    p->receiveDamage(baseAttack);
  }
}

#endif

/*
Zombie (bool) - Crea un zombie nuevo declarando si es jefe o no en el constructor de la madre, si es monstruo también declara el atributo resurrected como verdadero.
attack - Ataca a un player pero con un bonus extra de daño por quemadura.
*/