/*
 * Proyecto Shangri-La clase Monster
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * Esta clase define a un objeto Monster, el cuál es una clase abstracta que tiene
 * como hijos a zombie y dragonkin, esta clase y la clase Player interactuan
 * constantemente, principalmente con metodos que tienen apuntadores de la otra clase.
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Player;

class Monster{
  protected:
    int hp, baseAttack, index;
    bool boss;
    string type;
  public:
    Monster(bool);
    virtual void attack(Player*) = 0;
    void showInfo();
    int getHP(){return hp;}
    bool isAlive(){if (hp<=0) return false; else return true;}
    string getRace(){return type;}
    bool getBoss(){return boss;}
    void setIndex(int i){index=i;}
    void receiveDamage(int);
};

#include "Player.h"
// Este include se hace después de definir la clase para que attack pueda llamar un apuntador de Player

Monster::Monster(bool b){
  if (b){
    hp=50;
    baseAttack=10;
    boss=true;
  } else{
    hp=15;
    baseAttack=8;
    boss=false;
  }
}

void Monster::showInfo(){
  cout << "Health Points: " << hp << endl;
  cout << "Attack: " << baseAttack << endl;
  cout << "Race: " << type << endl;
}

void Monster::receiveDamage(int dmg){
  if (boss){
    hp-=dmg/2;
  } else{
    hp-=dmg;
  }
  if (hp<=0){hp=0;}
}

#endif

/*
Monster (bool) - Crea un nuevo monstruo con un bool que dice si es o no es Jefe.
@param bool Confirmacion de si es jefe o no
@return

attack - Esta función no tiene implementación así que su comportamiento se incluye en las hijas.
@param Player * apuntador de objeto Player
@return

showInfo - Muestra la informacion de monster.
@param
@return

getHP - Da la vida del monstruo.
@param
@return int devuelve hp del monstruo

isAlive - Checa si el monstruo está vivo.
@param
@return devuelve True si está vivo, false si no

getRace - Da la raza del monstruo (dragon o zombie).
@param
@return string devuelve el tipo de monstruo

getBoss - Dice si es boss.
@param
@return bool True si b es true, False si b es false

setIndex - Le da un index con respecto de una habitacion.
@param int indice a asignar
@return

receiveDamage - Recibe daño, pero si es jefe, solo la mitad del daño.
@param int daño recibido
@return
*/