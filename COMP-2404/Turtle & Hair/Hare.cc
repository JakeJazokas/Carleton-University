#include "Hare.h"
#include "Path.h"

int random(int);

Hare::Hare(){
  avatar = 'H'
  energyLevel = MAX_ENERGY;
  currenPosition = 0;
  down = false;
}

char Hare::getAvatar() { return avatar; }
int Hare::getEnergyLevel() { return energyLevel;}
int Hare::getPosition() { return currentPosition;}
bool Hare::isDown() { return down;}

void Hare::setEnergyLevel(int level)
{
  energyLevel = (level < 0) ? 0 : level;

  if (energyLevel == 0)
    down = true;
}

void Hare::setPosition(int pos)
{
  if (pos < 0) {
    currentPosition = 0;
}  else if (pos > Path::TOP_POS){
    currentPosition = Path::TOP_POS;
  } else {
    currentPosition = pos;
}

}

int Hare::updatePositon(){

  if (down)
    return currentPosition;

    int r, steps, currentPace;
//Compute random number between 1 and 10

r = random(10) + 1;

if (r<= 2) {    //sleep
  steps = 0;
  currentPace =0;
} else if (r<= 4) {    //big hop
  steps = 9;
  currentPace =3;
} else if ( r <= 5){   //big slip
  steps = -12;
  currentPace =0;
} else if ( r <= 8){   //small hop
  steps = 1;
  currentPace =1;
} else {
  steps =-2;
  currentPace = 0;
}


//decrease energy level according to current pace
setEnergyLevel(energyLevel- currentPace);

//if runner not down, update position by current number of steps
if (!down)
  setPosition(currentPosition + steps);

  return currentPosition;
}

void Hare::collide()
{
  setEnergyLevel(energyLevel(-3));
}

void Hare::eatSnack(){
  setEnergyLevel(MAX_ENERGY);
}
