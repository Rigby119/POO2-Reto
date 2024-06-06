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
    Room();
    Room(int);
    int getMonsterCount(){return monsterCount;}
    void addMonster(Monster*);
    void deleteMonsters();
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

void Room::deleteMonsters(){
  for (int i=0; i<monsterCount; i++){
    delete monsters[i];
  }
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