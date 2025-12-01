#include <IRremote.hpp>
#include <Wire.h>
#include "steppermotor.h"
#include "motorcontrol.h"



#define RECV_PIN 13
#define SLAVE_PIN 8
// isn't she so cutesy
StepMotor motor1(8, 9);
StepMotor motor2(5, 6);
StepMotor motor3(11, 12);
StepMotor motor4(2, 3);

MotorControl motors(motor1, motor2, motor3, motor4);
int steps(1600);

void setup() {
  Serial.begin(9600); // sets baud rate. 
  IrReceiver.begin(RECV_PIN); // Starts receiving IR info
  Wire.begin();
  motors.begin(); // initializes all motors at once

}

void loop() {
  if (IrReceiver.decode()) {
    auto code = IrReceiver.decodedIRData.decodedRawData;
    byte soleCom = 0;

    // the following switch case tells the slave which solenoids to activate :D
    switch(code) {
      case 0xE916FF00: // button 0
        soleCom = 1;
        break;
      case 0xE619FF00: // button EQ
        soleCom = 2;
        break;
      case 0xF20DFF00: // button ST / REPT
        soleCom = 3;
        break;
      case 0xF30CFF00: // button 1
        soleCom = 4;
        break;
      case 0xE718FF00: // button 2
        soleCom = 5;
        break;
      case 0xA15EFF00: // button 3
        soleCom = 6;
        break;
      case 0xF708FF00: // button 4
        soleCom = 7;
        break;
      case 0xE31CFF00: // button 5
        soleCom = 8;
        break;
      case 0xA55AFF00: // button 6
        soleCom = 9;
        break;
      case 0xBD42FF00: // button 7
        soleCom = 10;
        break;
      case 0xAD52FF00: // button 8
        soleCom = 11;
        break;
      case 0xB54AFF00: // button 9
        soleCom = 12;
        break;
      default: // if invalid button is pressed nothing occurs
        soleCom = 0;
        break;
    }

    if (soleCom != 0) {
      motors.reelAllIn(steps);

      Wire.beginTransmission(8);
      Wire.write(soleCom);
      Wire.endTransmission();
      delay(1000);
      
      motors.reelAllOut(steps);
    }
    IrReceiver.resume();
  }
}
