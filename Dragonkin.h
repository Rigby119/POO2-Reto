/*
 * Proyecto Shangri-La clase Dragonkin
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * La clase Dragonkin define a un objeto Dragonkin. Esta clase es hija de Monster y redefine
 * varios métodos de la clase Monster, incluyendo evidentemente el método pure virtual
 * que define a la clase Monster como abstracta. La principal diferencia de esta clase es un
 * parametro que funciona cómo un bonus de daño.
*/

#ifndef DRAGONKIN_H
#define DRAGONKIN_H

#include "Monster.h"

class Dragonkin : public Monster {
  private:
    int baseFireAttack;
  public:
    Dragonkin(bool);
    void attack(Player*);
};

Dragonkin::Dragonkin(bool b):Monster(b){
  baseFireAttack=4;
  type="Dragonkin";
}

void Dragonkin::attack(Player *p){
  p -> receiveDamage(baseAttack+baseFireAttack);
}

#endif

/*
Dragonkin (bool) - Crea un dragón nuevo declarando si es jefe o no en el constructor de la madre.
attack - Ataca a un player pero con un bonus extra de daño por quemadura.
*/