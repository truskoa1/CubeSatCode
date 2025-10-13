/* To further abstract our code, we have created a controller class to cause all motors to move simultaneously. Imagine this as stepper motor HQ. */
#ifndef CONTROL_H
#define CONTROL_H

#include "Arduino.h"
#include "steppermotor.h"

class MotorControl 
{
  public:
    MotorControl(StepMotor& m1, StepMotor& m2, StepMotor& m3, StepMotor& m4);

    void begin();
    void reelAllOut(int steps);
    void reelAllIn(int steps);

    void timed_together(int steps, int time);
  /* Lucky for us, we will never have more or less than 4 stepper motors! Due to this, we can use a pass-by-reference to access the memory location of our 4 motors.
  Imagine you have int x = 5 and int& y = x. You can then say y = 6 and x will also become 6! This allows us to "access" the data in these motor objects in our functions without
  having to copy all of it. This is kind of complicated, but I promise it works (plus, at least they aren't pointers) */
  private:
    StepMotor& motor1;
    StepMotor& motor2;
    StepMotor& motor3;
    StepMotor& motor4;
};

#endif