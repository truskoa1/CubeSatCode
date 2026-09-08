#ifndef SOL_H
#define SOL_H

#include "Arduino.h"

class Solenoid
{
  public:
    Solenoid(int pin);

    void sole_init();
    void timed_sole(int time);
  private:
    int sole_pin;

};

#endif
