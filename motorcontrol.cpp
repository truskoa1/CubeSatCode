#include "steppermotor.h"
#include "Arduino.h"
#include "motorcontrol.h"

MotorControl::MotorControl(StepMotor& m1, StepMotor& m2, StepMotor& m3, StepMotor& m4)
  : motor1(m1), motor2(m2), motor3(m3), motor4(m4) {}

// initializes all motors at once. This saves us quite a bit of typing lol
void MotorControl::begin() {
  motor1.begin();
  motor2.begin();
  motor3.begin();
  motor4.begin();
}
void MotorControl::reelAllOut(int steps) {
  motor1.reelOut(steps);
  motor2.reelOut(steps);
  motor3.reelOut(steps);
  motor4.reelOut(steps);
}
void MotorControl::reelAllIn(int steps) {
  motor1.reelIn(steps);
  motor2.reelIn(steps);
  motor3.reelIn(steps);
  motor4.reelIn(steps);
}

void MotorControl::timed_together(int steps, int time) {
  motor1.timed_motion(steps, time);
  motor2.timed_motion(steps, time);
  motor3.timed_motion(steps, time);
  motor4.timed_motion(steps, time);
}