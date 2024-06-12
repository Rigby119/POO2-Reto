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
  string clase;
  cout << "Dame el nombre de tu personaje #" << index << endl << ">>> ";
  getline(cin, nombre);
  cout << endl;
  while (true){
    cout << "Cual clase quieres que tenga? (ingresa el numero de tu eleccion)" << endl;
    cout << "1) Mago (Curacion)" << endl;
    cout << "2) Soldado (Ataques potentes)" << endl;
    cout << "3) Guardian (Resistencia y mas vida)" << endl;
    cout << ">>> ";
    getline(cin, clase);
    cout << endl;
    if (clase=="1"||clase=="2"||clase=="3"){
      break;
    } else{
      cout << "Por favor, introduce un numero valido." << endl << endl;
    }
  }
  if (clase=="1"){
    string elemento;
    while(true){
      cout << "La clase Mago tiene un atributo especial, escoge cual prefieres (ingresa el numero de tu eleccion)" << endl;
      cout << "1) Mago de Luz (Hace mas daño a los zombies)" << endl;
      cout << "2) Mago de Oscuridad (Hace mas daño a los dragonoides)" << endl;
      cout << ">>> ";
      getline(cin, elemento);
      cout << endl;
      if (elemento=="1"){
        players[numP]=new Mage(nombre, "Light");
        break;
      } else if (elemento=="2"){
        players[numP]=new Mage(nombre, "Dark");
        break;
      } else{
        cout << "Por favor, introduce un numero valido." << endl << endl;
      }
    }
  } else if (clase=="2"){
    players[numP]=new Soldier(nombre);
  } else if (clase=="3"){
    players[numP]=new Guardian(nombre);
  }
  numP++;
}

void atacar(int idx, Room* r){
  string monster;
  while (true){
    cout << "A que monstruo atacaras? (introduce un numero del 1 al 3)" << endl;
    cout << ">>> ";
    getline(cin, monster);
    cout << endl;
    if (monster=="1"){
      players[idx]->attack(r->monsters[0]);
      break;
    } else if (monster=="2"){
      players[idx]->attack(r->monsters[1]);
      break;
    } else if (monster=="3"){
      players[idx]->attack(r->monsters[2]);
      break;
    } else{
      cout << "Por favor, introduce un numero valido." << endl << endl;
    }
  }
}

void turn(int idx, Room* r){
  int idx2;
  if (idx==0){idx2=1;} else{idx2=0;}
  string opcion;
  cout << "Turno de " << players[idx]->getName() << endl << endl;
  if (players[idx]->getClass()=="Mage"){
    while (true){
      cout << "Quieres atacar un monstruo o curar a un aliado? (introduce un numero del 1 al 2)" << endl;
      cout << "1) Atacar" << endl;
      cout << "2) Curar" << endl;
      cout << ">>> ";
      getline(cin, opcion);
      cout << endl;
      if (opcion=="1"||opcion=="2"){
        break;
      } else{
        cout << "Por favor, introduce un numero valido." << endl << endl;
      }
    }
    if (opcion=="1"){
      atacar(idx, r);
    } else{
      players[idx]->heal(players[idx2]);
    }
  } else{
    atacar(idx, r);
  }
  
}

void turnB(int idx, Room* r){
  int idx2;
  if (idx==0){idx2=1;} else{idx2=0;}
  string opcion;
  cout << "Turno de " << players[idx]->getName() << endl << endl;
  if (players[idx]->getClass()=="Mage"){
    while (true){
      cout << "Quieres atacar un monstruo o curar a un aliado? (introduce un numero del 1 al 2)" << endl;
      cout << "1) Atacar" << endl;
      cout << "2) Curar" << endl;
      cout << ">>> ";
      getline(cin, opcion);
      cout << endl;
      if (opcion=="1"||opcion=="2"){
        break;
      } else{
        cout << "Por favor, introduce un numero valido." << endl << endl;
      }
    }
    if (opcion=="1"){
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
  string info;
  cout << "Bienvenido a Shangri-La Frontier" << endl << endl;
  while(true){
    cout << "Quisieras saber acerca del juego antes de empezar? (ingresa el numero de tu eleccion)" << endl << "1) Si" << endl << "2) No"<< endl;
    cout << ">>> ";
    getline(cin, info);
    cout << endl;
    if (info=="1"){
      descripcion();
      break;
    } else if (info=="2"){
      break;
    } else{
      cout << "Por favor, introduce un numero valido." << endl << endl;
    }
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