#ifndef TORTOISE_H
#define TORTOISE_H

#include "Runner.h"


class Tortoise : public Runner {
public:
  Tortoise();
  virtual voide updatePositon();
};

/*
class Tortoise{

public:
  Tortoise();
  int getPosition();
  int updatePosition();
  char getAvatar;
  int getEnergyLevel();
  bool isDown();
  void eatSnack();
  const static int MAX_ENERGY = 25;

private:
  int currentPosition;
  char avatar;
  int energyLevel;
  bool down;
  void setEnergyLevel(int);
  void setPosition(int);
};
*/
#endif
