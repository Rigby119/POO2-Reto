/*
 * Proyecto Shangri-La clase Dungeon y clase Room
 * Roberto Serna Niño
 * A01709577
 * 12/06/2024
 * version : 5
 * La clase Dungeon define a un objeto Dungeon, el cuál es una clase que contiene un número
 * de objetos de tipo Room. El constructor de Dungeon crea al mismo tiempo los objetos de
 * Room que estarán dentro y añade los monstruos que Room contiene.
 * La clase Room define a un objeto Room, el cuál contiene máximo 3 monstruos que son creados y
 * luego añadidos a este. Por lo tanto Dungeon se compone de Room y a Room se le asignan objetos
 * de tipo Monster.
*/

#ifndef DUNGEON_H
#define DUNGEON_H

#include "Monster.h"
#include "Dragonkin.h"
#include "Zombie.h"

class Room{
  private:
    int monsterCount, index;
  public:
    Monster *monsters[3];
    Room(int);
    int getMonsterCount(){return monsterCount;}
    void addMonster(Monster*);
    void showInfo();
    bool monstersAlive();
    void clearRoom();
};

Room::Room(int i){
  monsterCount=0;
  index=i;
}

void Room::addMonster(Monster* m){
  monsters[monsterCount]=m;
  monsters[monsterCount]->setIndex(monsterCount);
  monsterCount++;
}

void Room::showInfo(){
  for (int i=0; i<monsterCount; i++){
    cout << "Monster #" << i+1 << endl;
    if (monsters[i]->getBoss()){
      cout << "--BOSS MONSTER--" << endl;
    }
    monsters[i] -> showInfo();
    cout << endl;
  }
}

void Room::clearRoom(){
  cout << "Room " << index << " cleared!" << endl << endl;
}

bool Room::monstersAlive(){
  bool boolean=false;
  for (int i=0; i<3; i++){
    if (monsters[i]->isAlive()){
      boolean=true;
    }
  }
  return boolean;
}

class Dungeon{
  public:
    Room* rooms[4];

    Dungeon(string);
    void showDungeon();
    void clearDungeon();
};

Dungeon::Dungeon(string bossRace){
  for (int i=0; i<3; i++){
    rooms[i] = new Room(i+1);
    if (i%2==1){
      rooms[i] -> addMonster(new Dragonkin(false));
      rooms[i] -> addMonster(new Zombie(false));
      rooms[i] -> addMonster(new Dragonkin(false));
    } else{
      rooms[i] -> addMonster(new Zombie(false));
      rooms[i] -> addMonster(new Dragonkin(false));
      rooms[i] -> addMonster(new Zombie(false));
    }
  }
  if (bossRace=="Dragonkin"){
    rooms[3] = new Room(4);
    rooms[3] -> addMonster(new Dragonkin(true));
  } else{
    rooms[3] = new Room(4);
    rooms[3] -> addMonster(new Zombie(true));
  }
}

void Dungeon::showDungeon(){
  for (int i=0; i<4; i++){
    cout << "Room " << i+1 << endl << endl;
    rooms[i] -> showInfo();
  }
}

void Dungeon::clearDungeon(){
  cout << "Dungeon cleared!" << endl << endl;
}

#endif

/*
PARA LA CLASE ROOM

Room (int) - Crea una nueva habitación con un índice.
getMonsterCount - Da la cantidad de monstruos que hay en la hab.
addMonster - Añade un Monstruo a la hab con un límite de 3 monstruos.
showInfo - Muestra la información de cada monstruo llamando su showInfo.
monstersAlive - Si hay al menos un monstruo vivo regresa un valor verdadero.
clearRoom - Muestra que ya se limpió la habitacion.

PARA LA CLASE DUNGEON

Dungeon(string) - Crea un nuevo Dungeon con un boss de la raza que se ingrese (Dragonkin or Zombie).
showDungeon - Muestra la información de las habitaciones del dungeon que a su vez muestra la info de los monstruos
clearDungeon - Muestra que ya se terminó la dungeon
*/