#include "Arduino.h"

#ifndef VALVE_H
#define VALVE_H 

class Valve {
  public:
    //Constructor for the vavle
    Valve(int pin);
    // Initialize the valve pin
    void begin();
    // Optional: Trigger the valve for a specific duration (in milliseconds)
    void triggerForDuration(unsigned long duration);
    void trigger();
  private:
    int pin;
};
#endif