#ifndef HARE_H
#define HARE_H

class Hare{

public:
  Hare();
  int getPosition();
  int updatePosition();
  void collide();
  char getAvatar();
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
  bool setPosition(int);

};
#endif
