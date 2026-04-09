/* In C++, it is convention to "create" a class in a header file (*.h) and implement it in a separate *.cpp file. Here I create a stepper motor class
to abstract our code. C++ is object oriented, so this creates a class so we can make four separate stepper motor objects. */

// this prevents this class from being included twice.
#ifndef STEP_H
#define STEP_H

#include "Arduino.h"

class StepMotor
{
  /* in brief, there are public and private attributes in classes. The items I have in the private part of this class
  do not need to be directly accessed by the user. This helps us to not shoot ourselves in the foot. Plus it's C convention. */
  public:
    StepMotor(int pul, int dir);

    /* here's the meat and potatoes. This is what makes that jawn run. We leave "steps" as a variable because
    this value will change with further testing. PLEASE do not run a sketch using this class without assigning it a
    value because the junk data held in an undeclared variable could be wack large */
    void begin();
    void reelOut();
    void reelIn();

    /* this is in case we want a timed motion instead of user controlled. I'm implementing 
    it here so the class can remain as untouched as possible. */
    void timed_motion(int steps, int time);
  private:
    int pul_pin;
    int dir_pin;
};
#endif