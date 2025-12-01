#include "Arduino.h"
#include "solenoid.h"
#include "solenoidcontrol.h"

SolenoidControl::SolenoidControl(int sol1, int sol2) {
  solpin1 = sol1;
  solpin2 = sol2;
};

void SolenoidControl::all_init() {
  pinMode(solpin1, OUTPUT);
  pinMode(solpin2, OUTPUT);
};
void SolenoidControl::all_timed_sole(int time) {
  digitalWrite(solpin1, HIGH);
  digitalWrite(solpin2, HIGH);
  delay(time);
  digitalWrite(solpin1, LOW);
  digitalWrite(solpin2, LOW);
};
