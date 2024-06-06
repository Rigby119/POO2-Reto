#include <iostream>

#include "Player.h"
#include "Mage.h"
#include "Soldier.h"
#include "Guardian.h"
#include "Dungeon.h"
#include "Monster.h"
#include "Dragonkin.h"
#include "Zombie.h"

#include "Descripcion.h"

using namespace std;

Player* players[2];
int numP=0;

void showPlayers(){
  for (int i=0; i<numP; i++){
    cout << "Player " << i+1 << endl << endl;
    players[i] -> showInfo();
    cout << endl;
  }
}

void crearPersonaje(int index){
  string nombre;
  int clase;
  cout << "Dame el nombre de tu personaje #" << index << endl << ">>> ";
  cin >> nombre;
  cout << endl;
  cout << "¿Cuál clase quieres que tenga? (ingresa el número de tu elección)" << endl;
  cout << "1) Mago (Curación)" << endl;
  cout << "2) Soldado (Ataques potentes)" << endl;
  cout << "3) Guardían (Resistencia y más vida)" << endl;
  cout << ">>> ";
  cin >> clase;
  cout << endl;
  if (clase == 1){
    int elemento;
    cout << "La clase Mago tiene un atributo especial, escoge cuál prefieres (ingresa el número de tu elección)" << endl;
    cout << "1) Mago de Luz (Hace más daño a los zombies)" << endl;
    cout << "2) Mago de Oscuridad (Hace más daño a los dragonoides)" << endl;
    cout << ">>> ";
    cin >> elemento;
    cout << endl;
    if (elemento==1){
      players[numP]=new Mage(nombre, "Light");
    }  else if (elemento==2){
      players[numP]=new Mage(nombre, "Dark");
    }
  } else if (clase==2){
    players[numP]=new Soldier(nombre);
  } else if (clase==3){
    players[numP]=new Guardian(nombre);
  }
  numP++;
}

void turn(int idx, Room* r){
  int idx2;
  if (idx==0){idx2=1;} else{idx2=0;}
  int monster;
  int opcion;
  cout << "Turno de " << players[idx]->getName() << endl << endl;
  if (players[idx]->getClass()=="Mage"){
    cout << "¿Quieres atacar un monstruo o curar a un aliado? (introduce un número del 1 al 2)" << endl;
    cout << "1) Atacar" << endl;
    cout << "2) Curar" << endl;
    cout << ">>> ";
    cin >> opcion;
    cout << endl;
    if (opcion==1){
      cout << "¿A qué monstruo atacarás? (introduce un número del 1 al 3)" << endl;
      cout << ">>> ";
      cin >> monster;
      cout << endl;
      players[idx]->attack(r->monsters[monster-1]);
    } else{
      players[idx]->heal(players[idx2]);
    }
  } else{
    cout << "¿A qué monstruo atacarás? (introduce un número del 1 al 3)" << endl;
    cout << ">>> ";
    cin >> monster;
    cout << endl;
    players[idx]->attack(r->monsters[monster-1]);
  }
}

void turnB(int idx, Room* r){
  int idx2;
  if (idx==0){idx2=1;} else{idx2=0;}
  int opcion;
  cout << "Turno de " << players[idx]->getName() << endl << endl;
  if (players[idx]->getClass()=="Mage"){
    cout << "¿Quieres atacar al jefe o curar a un aliado? (introduce un número del 1 al 2)" << endl;
    cout << "1) Atacar" << endl;
    cout << "2) Curar" << endl;
    cout << ">>> ";
    cin >> opcion;
    cout << endl;
    if (opcion==1){
      players[idx]->attack(r->monsters[0]);
    } else{
      players[idx]->heal(players[idx2]);
    }
  } else{
    players[idx]->attack(r->monsters[0]);
  }
}

int getMaxHPplayer(){
  int hp1=players[0]->getHP();
  int hp2=players[1]->getHP();
  if (hp1>hp2){return 0;} else{return 1;}
}

void monsterTurn(Room* r){
  for (int mst=0; mst<r->getMonsterCount(); mst++){
    if (r->monsters[mst]->isAlive()){
      cout << "Turno de monstruo " << mst+1 << endl << endl;
      r->monsters[mst]->attack(players[getMaxHPplayer()]);
    }
  }
}

void bossTurn(Room* r){
  if (r->monsters[0]->isAlive()){
    cout << "Turno de jefe" << endl << endl;
    r->monsters[0]->attack(players[getMaxHPplayer()]);
  }
}


int main() {
  bool info;
  cout << "¡Bienvenido a Shangri-La Frontier!" << endl << endl;
  cout << "¿Quisieras saber acerca del juego antes de empezar? (ingresa el número de tu elección)" << endl << "0) Sí" << endl << "1) No"<< endl;
  cout << ">>> ";
  cin >> info;
  cout << endl;
  if (!info){
    descripcion();
  }
  cout << "Ahora crearemos tus personajes" << endl << endl;
  crearPersonaje(1);
  crearPersonaje(2);
  
  showPlayers();

  cout << "Todo listo, entremos a una mazmorra." << endl << endl;
  Dungeon* dung = new Dungeon("Dragonkin");

  bool dungF=false;
  
  for (int rm=0; rm<3; rm++){
    if (dungF){
      cout << "Dungeon Failed" << endl;
      break;
    }
    cout << "Room " << rm+1 << endl << endl;
    while (true){
      for (int plyr=0; plyr <2; plyr++){
        if (players[plyr]->isAlive()){
          turn(plyr, dung -> rooms[rm]);
        }
      }
      monsterTurn(dung -> rooms[rm]);
      showPlayers();
      dung->rooms[rm]->showInfo();
      if (!(players[0]->isAlive())&&!(players[1]->isAlive())){
        dungF=true;
        break;
      } else if (!dung->rooms[rm]->monstersAlive()){
        dung->rooms[rm]->clearRoom();
        break;
      }
    }
  }
  if (!dungF){
    cout << "Boss Room" << endl << endl;
    while (true){
      for (int plyr=0; plyr <2; plyr++){
        if (players[plyr]->isAlive()){
          turnB(plyr, dung -> rooms[3]);
        }
      }
      bossTurn(dung -> rooms[3]);
      showPlayers();
      dung->rooms[3]->showInfo();
      if (!(players[0]->isAlive())&&!(players[1]->isAlive())){
        dungF=true;
        break;
      } else if (!dung->rooms[3]->monsters[0]->isAlive()){
        dung->clearDungeon();
        break;
      }
    }
    if (dungF){
      cout << "Dungeon Failed" << endl;
    }
  }
  return 0;
}