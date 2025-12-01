#ifndef SOLCONTROL_H
#define SOLCONTROL_H

#include "Arduino.h"
#include "solenoid.h"

class SolenoidControl {
  public:
    SolenoidControl(int sol1, int sol2);

    void all_init();
    void all_timed_sole(int time);

  private:
    int solpin1;
    int solpin2;
};

#endif