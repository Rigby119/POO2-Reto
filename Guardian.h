/*
 * Proyecto Shangri-La clase Guardian
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * Esta clase define a un objeto de personaje con un rol de guardian, este tiene algunas
 * sobreescrituras de métodos definidos en la clase Player que principalmente agregan
 * funcionalidad con atributos especiales que solo están en esta clase, en este caso
 * sería la defensa del personaje.
*/

#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "Player.h"

class Guardian : public Player{
  private:
    int dp;
  public:
    Guardian(string);
    void showInfo();
    void updateAttributes();
    void increaseExp(float);
    void receiveDamage(int dmg){hp-=(dmg-dp);};
    void attack(Monster*);
};

Guardian::Guardian(string nm) : Player(nm){
  dp=3;
  hp+=5;
  maxHP+=5;
  type="Guardian";
}

void Guardian::showInfo(){
  cout << "Name: " << name << endl;
  cout << "Class: " << type << endl;
  cout << "Level: " << level << endl;
  cout << "HP: " << hp << "/" << maxHP << endl;
  cout << "Experience Points: " << exp << endl;
  cout << "Base Attack: " << baseAttack << endl;
  cout << "Defense Points: " << dp << endl;
}

void Guardian::increaseExp(float newExp){
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

void Guardian::updateAttributes(){
  maxHP+=10;
  hp=maxHP;
  baseAttack+=3;
}

void Guardian::attack(Monster* m){
  bool alive = m->isAlive();
  m->receiveDamage(baseAttack);
  if (alive && !m->isAlive()){
    increaseExp(50);
  }
}

#endif

/*
Guardian(string) - Crea un nuevo Mage que solo pide un nombre, el elemento es asignado de manera aleatoria.
@param string nombre del Player
@return

showInfo - Muestra la información del personaje sobreescribiendo el método de Player.
@param
@return

updateAttributes - Actualiza los puntos de defensa, la vida base y actual del jugador así cómo su daño base.
@param
@return

increaseExp - Incrementa la experiencia que tiene el personaje y si llega a un tope, sube de nivel, actualizando sus atributos en el proceso.
(este metodo es creado en las hijas y no en la madre debido a que llama a update attributes que no está en la madre y cambia en cada hija)
@param float experiencia ganada
@return

receiveDamage - Le hace daño al jugador pero en este caso es un daño reducido gracias a los puntos de defensa del Guardian
@param int daño recibido
@return

attack - Ataca a un monstruo, sobreescribiendo el método de Player.
@param Monster* apuntador al Monster atacado
@return
*/