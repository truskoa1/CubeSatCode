#include <IRremote.hpp>
#include "steppermotor.h"
#include "motorcontrol.h"


#define RECV_PIN 13
// isn't she so cutesy
StepMotor motor1(8, 9);
StepMotor motor2(5, 6);
StepMotor motor3(11, 12);
StepMotor motor4(2, 3);

MotorControl motors(motor1, motor2, motor3, motor4);
int steps(1600);
bool extended = false; // should start as false

void setup() {
  Serial.begin(9600); // sets baud rate. 
  IrReceiver.begin(RECV_PIN); // Starts receiving IR info

  motors.begin(); // initializes all motors at once
}

void loop() {
  if (IrReceiver.decode()) {
    auto code = IrReceiver.decodedIRData.decodedRawData;
    if (!extended) {
      motors.reelAllOut(steps);
      extended = true;
      IrReceiver.resume();
    }
    else {
      motors.reelAllIn(steps);
      extended = false;
      IrReceiver.resume();
    }
    IrReceiver.resume();
  }
}
