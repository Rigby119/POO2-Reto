#include <iostream>
#include "Player.h"
#include "Mage.h"
#include "Soldier.h"
#include "Guardian.h"
#include "Dungeon.h"
#include "Boss.h"

using namespace std;

float randomize(float base, int level);

int randomize(int hp, int level);

int main() {
  Mage Alfredito("Alfred");
  Alfredito.showInfo();
  cout << endl;
  Guardian Juanita("Jane");
  Juanita.showInfo();
  cout << endl;
  Soldier Pedrito("Mace", "Pierre");
  Pedrito.showInfo();
  cout << endl;
  Alfredito.increaseExp(100.0);
  Alfredito.showInfo();
  cout << endl;
  Juanita.increaseExp(100.0);
  Juanita.showInfo();
  cout << endl;
  Pedrito.increaseExp(100.0);
  Pedrito.showInfo();
  cout << endl;
  Pedrito.increaseExp(50.0);
  Pedrito.showInfo();
  cout << endl;
  Boss zombie(20, 5, 5, "Spartan Zombie");
  zombie.monsterAttack(&Juanita);

  Juanita.showInfo();
  cout << endl;
  Alfredito.heal(&Juanita);
  Juanita.showInfo();
  cout << endl;
  Alfredito.attack(&zombie);

  cout << zombie.getHP();
  cout << endl;
}