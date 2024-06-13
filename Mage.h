/*
 * Proyecto Shangri-La clase Mage
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * Esta clase define a un objeto de personaje con un rol de mago, este tiene algunas
 * sobreescrituras de métodos definidos en la clase Player que principalmente agregan
 * funcionalidad con atributos especiales que solo están en esta clase, en este caso
 * sería el elemento del mago.
*/

#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player{
  private:
    string element;
  public:
    Mage(string);
    Mage(string, string);
    void showInfo();
    void heal(Player*);
    void increaseExp(float);
    void updateAttributes();
    void attack(Monster*);
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
  if (p->isAlive()){
    int cura = (p->getMaxHP()-p->getHP())/2;
    p -> setHP(cura+p->getHP());
  }
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
  baseAttack+=3;
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

/*
Mage (string) - Crea un nuevo Mage que solo pide un nombre, el elemento es asignado de manera aleatoria.
Mage (string, string) - Crea un nuevo Mage que pide el nombre y el elemento.
showInfo - Muestra la información del personaje sobreescribiendo el método de Player.
heal - Cura a otro personaje usando su apuntador sobreescribiendo el método de Player.
increaseExp - Incrementa la experiencia que tiene el personaje y si llega a un tope, sube de nivel, actualizando sus atributos en el proceso.
(este metodo es creado en las hijas y no en la madre debido a que llama a update attributes que no está en la madre y cambia en cada hija)
updateAttributes - Actualiza la vida base y actual del jugador así cómo su daño base.
attack - Ataca a un monstruo, sobreescribiendo el método de Player, dependiendo del elemento del mago y del tipo de monstruo puede hacer más o menos daño.
*/