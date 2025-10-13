/* Right now we have a lot of redundant code in our sketch. Here I will implement a class to abstract
our stepper motors. This allows us to easily change our sketch to do various tests without having to completely 
rewrite our code! */
#include "steppermotor.h"
#include "Arduino.h"

// this is called a constructor. it "makes" the object. This basically states that all the motors depend on two integer pins. 
StepMotor::StepMotor(int pul, int dir) {
  pul_pin = pul;
  dir_pin = dir; // dih pin 🥀 💔
}

// initializes motors
void StepMotor::begin() {
  pinMode(pul_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
}

void StepMotor::reelOut() {
  digitalWrite(dir_pin, HIGH);
  digitalWrite(pul_pin, HIGH);
  delayMicroseconds(200); // we have to have these delays because code moves very fast and stepper motors do not. we could have this faster I think but not by much.
  digitalWrite(pul_pin, LOW);
  delayMicroseconds(200);
}
void StepMotor::reelIn() {
  digitalWrite(dir_pin, LOW);
  digitalWrite(pul_pin, HIGH);
  delayMicroseconds(200);
  digitalWrite(pul_pin, LOW);
  delayMicroseconds(200);
}
// fix this lol
void StepMotor::timed_motion(int steps, int time) {
  digitalWrite(dir_pin, HIGH);
  for (int i = 0; i < steps; i++) {
    digitalWrite(pul_pin, HIGH);
    delayMicroseconds(500); 
    digitalWrite(pul_pin, LOW);
    delayMicroseconds(500);
  }
  delay(time); // this pauses for a set amount of time before the next loop begins. 

  digitalWrite(dir_pin, LOW);
  for (int i = 0; i < steps; i++) {
    digitalWrite(pul_pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(pul_pin, LOW);
    delayMicroseconds(500);
  }
}







