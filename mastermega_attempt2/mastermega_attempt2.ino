#include <IRremote.hpp>
#include <Wire.h>

#define SLAVE_ADDR 8            // I2C address of the slave Arduino
#define RECV_PIN 13             // IR receiver pin

// IR codes for solenoid valves
#define SOL1_BTN  0xF30CFF00    // Button for solenoid 1
#define SOL2_BTN  0xE718FF00    // Button for solenoid 2
#define SOL3_BTN  0xA15EFF00    // Button for solenoid 3

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.begin(RECV_PIN);      // Start IR receiver
  Wire.begin();                // Join I2C bus as master

  Serial.println("Master ready to control solenoids via IR.");
}

void loop() {
  if (irrecv.decode()) {
    uint32_t code = irrecv.decodedIRData.decodedRawData;
    Serial.print("Received IR code: ");
    Serial.println(code, HEX);
    irrecv.resume();  // Ready to receive the next IR code

    // Send command based on IR code
    if (code == SOL1_BTN) {
      sendToSlave(1);
    } else if (code == SOL2_BTN) {
      sendToSlave(2);
    } else if (code == SOL3_BTN) {
      sendToSlave(3);
    } else {
      Serial.println("Unknown button.");
    }
  }
}

void sendToSlave(uint8_t solenoidID) {
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(solenoidID);           // Send solenoid ID (1–3)
  Wire.endTransmission();

  Serial.print("Sent command to activate solenoid ");
  Serial.println(solenoidID);
}
