/*
 * Proyecto Shangri-La clase Soldier
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * Esta clase define a un objeto de personaje con un rol de soldado, este tiene algunas
 * sobreescrituras de métodos definidos en la clase Player que principalmente agregan
 * atributos a los métodos o cambian los ya definidos (en este caso el daño de los ataques).
*/

#ifndef SOLDIER_H
#define SOLDIER_H

#include "Player.h"

class Soldier : public Player{
  public:
    Soldier(string);
    void showInfo();
    void increaseExp(float);
    void updateAttributes();
    void attack(Monster*);
};

Soldier::Soldier(string nm):Player(nm){
  baseAttack=15;
  type="Soldier";
}

void Soldier::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << "/" << maxHP << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
};

void Soldier::increaseExp(float newExp){
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

void Soldier::updateAttributes(){
  maxHP+=5;
  hp=maxHP;
  baseAttack+=6;
}

void Soldier::attack(Monster* m){
  bool alive = m->isAlive();
  m->receiveDamage(baseAttack);
  if (alive && !m->isAlive()){
    increaseExp(50);
  }
}

#endif

/*
Soldier(string)- Crea un nuevo Soldier que solo pide un nombre para crear conforme a Player().
@param string nombre del Player
@return

showInfo - Muestra la información del personaje sobreescribiendo el método de Player.
@param
@return

increaseExp - Incrementa la experiencia que tiene el personaje y si llega a un tope, sube de nivel, actualizando sus atributos en el proceso.
(este metodo es creado en las hijas y no en la madre debido a que llama a update attributes que no está en la madre y cambia en cada hija)
@param float cantidad de experiencia recibida
@return

updateAttributes - Actualiza la vida base y actual del jugador así cómo su daño base, el cuál aumenta más para Soldier que para las otras clases.
@param
@return

attack - Ataca a un monstruo, sobreescribiendo el método de Player.
@param Monster* apuntar al objeto Monster
@return
*/