#ifndef RUNNER_H
#define RUNNER_H

class Runner{

public:
  Runner();
  int getPosition();
  virtual int updatePosition() = 0;
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
