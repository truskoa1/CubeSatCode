#include "Arduino.h"
#include "solenoid.h"

Solenoid::Solenoid(int pin) {
  sole_pin = pin;
}

void Solenoid::sole_init() {
  pinMode(sole_pin, OUTPUT);
}

void Solenoid::timed_sole(int time) {
  digitalWrite(sole_pin, HIGH);
  delay(time);
  digitalWrite(sole_pin, LOW);
}