#include "Tortoise.h"
#include "Path.h"

int random(int);

Tortoise::Tortoise(){

  avatar = 'T';
  energyLevel = MAX_ENERGY;
  currentPosition = 0;
  down = false;
}

char Tortoise::getAvatar() { return avatar; }
int  Tortoise::getPosition() { return currenPosition; }
int  Tortoise::getEnergyLevel() { return energyLevell }
bool Tortoise::isDown(){            return down;}

void Tortoise::setEnergyLevel(int level)
{
  energyLevel = (level < 0) ? 0 : level;

  if (energyLevel == 0)
    down = true;
}

void Tortoise::setPosition(int pos)
{
  if (pos < 0) {
    currentPosition = 0;
}  else if (
    pos > Path::TOP_POS){
    currentPosition = Path::TOP_POS;
  } else {
    currentPosition = pos;
}

}

int Tortoise::updatePositon(){

  int r, steps, currentPace;
  if (down)
    return currentPosition;
//Compute random number between 1 and 10

r = random(10) + 1;

if (r<= 5) {    //FAST PLOD
  steps = 3;
  currentPace =2;
} else if (r<= 7) {    //FAST PLOD
  steps = -6;
  currentPace =0;
} else {   //SLOW PLOD
  steps = 1;
  currentPace =1;
}


//decrease energy level according to current pace
setEnergyLevel(energyLevel- currentPace);

//if runner not down, update position by current number of steps
if (!down)
  setPosition(currentPosition + steps);

  return currentPosition;
}

void Tortoise::eatSnack()
{
  setEnergyLevel(MAX_ENERGY);
}
