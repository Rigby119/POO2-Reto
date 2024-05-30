#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>
using namespace std;

class Monster{
  protected:
    int HP, attack;
  public:
    Monster(int, int);
    void receiveDamage(int dmg);
    void kill(); //Destruir el objeto
    int getHP(){return HP;}
};

Monster::Monster(int h, int a){
  HP=h;
  attack=a;
}

void Monster::receiveDamage(int dmg){
  HP=HP-dmg;
}

class Room{
  public:
    Monster *monsters[5];
    void clearRoom();
};

class Dungeon{
  public:
    Room rooms[4];
    void clearDungeon();
};

#endif