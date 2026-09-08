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
  for (int i = 0; i < steps; i++) {
    motor1.reelOut();
    motor2.reelOut();
    motor3.reelOut();
    motor4.reelOut();
  }
}
void MotorControl::reelAllIn(int steps) {
  for (int i = 0; i < steps; i++) {
    motor1.reelIn();
    motor2.reelIn();
    motor3.reelIn();
    motor4.reelIn();
  }
}
// fix this too
void MotorControl::timed_together(int steps, int time) {
  motor1.timed_motion(steps, time);
  motor2.timed_motion(steps, time);
  motor3.timed_motion(steps, time);
  motor4.timed_motion(steps, time);
}