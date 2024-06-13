/*
 * Proyecto Shangri-La clase Player
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * Esta clase define a un objeto de personaje que tiene las funciones principales para
 * atacar a monstruos y subir de nivel al derrotarlos, esta clase es la clase madre de 
 * cada una de las clases de rol (Guardian, Mage y Soldier).
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Monster;

class Player{
  protected:
    string name, type;
    int level, hp, maxHP;
    float exp, baseAttack;
  public:
    Player(string);
    string getName(){return name;}
    string getClass(){return type;}
    int getHP(){return hp;}
    int getMaxHP(){return maxHP;}
    bool isAlive(){if (hp<=0) return false; else return true;}
    void setHP(int newHp){if (newHp<=0){hp=0;} else {hp=newHp;}}
    virtual void showInfo(){cout << name;}
    virtual void heal(Player*) {cout << "";}
    virtual void receiveDamage(int dmg){hp-=dmg; if(hp<0){hp=0;}}
    virtual void attack(Monster*) {cout << "";}
};

#include "Monster.h"
// Este include se hace después de definir la clase para que attack pueda llamar un apuntador de monstruo

Player::Player(string nm){
  name=nm;
  level=0;
  hp=30;
  maxHP=30;
  exp=0.0;
  baseAttack=10;
};

#endif

/*
Player(string) - Crea un nuevo Player con atributos por defecto y un nombre solicitado en parametros.
@param string nombre del Player
@return

getName - Da el nombre del Player.
@param
@return string nombre del Player name

getClass - Da la clase del Player.
@param
@return string clase del Player type

getHP - Da la vida del Player.
@param
@return int vida actual hp

getMaxHP - Da la vida máxima del Player.
@param
@return int vida maxima maxHP

showInfo - Función para mostrar la información del usuario pero que será sobreescrita por las hijas.
@param
@return

isAlive - Dice si el jugador sigue vivo (sí o no).
@param
@return bool True si está vivo, False si no

setHP - Le da un nuevo valor a la vida del jugador, si el nuevo valor es menor que 0, entonces se queda en 0.
@param int nuevo valor de hp
@return

heal - Método de la clase Mage que es creado en Player debido a que el main lo llamará usando el apuntador a un objeto tipo Player, será sobreescrito en Mage.
@param Player* apuntador al Player a curar
@return

receiveDamage - Método en el que reciben daño los jugadores, se sobreescribirá unicamente en la clase Guardian mientras que Soldier y Mage lo usaran cómo está declarado aquí.
@param int daño recibido
@return

attack - Método para atacar a un monstruo, se sobreescribe en todos los hijos .
@param Monster* apuntador al Monster atacado
@return
*/