#include <iostream>
#include <iomanip>
using namespace std;
#include "Race.h"

Race::Race() : over(false) {}

bool Race::isOver() { return over;}

void Race::update() {

int oldTortPos, oldHarePos;
int newTortPos, newHarePos;

//Save current runner positions
oldTortPos = timmy.getPosition();
oldHarePos = harold.getPosition();

//Move runners
newTortPos = timmy.updatePosition();
newHarePos = harold.updatePosition();

//Both runners' positions are updated on the path
path.moveCharacter(timmy.getAvatar, oldTortPos, newTortPos);
path.moveCharacter(harold.getAvatar, oldTortPos, newHarePos);

if(newHarePos == newTortPos) {
//collision occurs

path.setCollision(newHarePos);
harold.collide();
}

else {

if(path.getPathPos(newTortPos).hasSnack()) {
//Tortoise finds a snack
timmy.eatSnack();
path.removeSnack(newTortPos);
}

if(path.getPathPos(newHarePos).hasSnack())
//Hare finds a snack
harold.eatSnack();
path.removeSnack(newHarePos);
}
}

//Path is printed out
path.print();
cout << setw(2)<<setfill('0')<< timmy.getEnergyLevel()<<endl;

//check for winner

if(timmy.isDown() && harold.isDown()) {
  cout << "both mandems are dead!" << endl;
  over = true;
}

else if(newTortPos >= Path::TOP_POS && newHarePos >= Path::TOP_POS) {
  cout << "Its a tie!!!" << endl;
  over = true;
}

else if (newTortPos >+ Path::TOP_POS) {
  cout << "Timmy wins!!!" << endl;
  over = true;
}

else if (newHarePos >+ Path::TOP_POS) {
  cout << "Harold wins!!!" << endl;
  over = true;
}
}
