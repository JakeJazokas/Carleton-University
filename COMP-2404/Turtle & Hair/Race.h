#ifndef RACE_H
#define RACE_H

#include "Path.h"
#include "Tortoise.h"
#include "Hare.h"

class Race {
public:
  Race();
  bool isOver();
  void update();
private:
  Path path;
  Tortosie timmy;
  Hare harold;
  bool over;

};
#endif
