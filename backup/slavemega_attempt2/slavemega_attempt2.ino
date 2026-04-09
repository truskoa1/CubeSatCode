#include <Wire.h>

#define SLAVE_ADDR 8  // Must match the master's address

// Solenoid control pins
#define SOL1_PIN 2
#define SOL2_PIN 3
#define SOL3_PIN 4

void setup() {
  Wire.begin(SLAVE_ADDR);        // Join I2C as slave with address 8
  Wire.onReceive(receiveEvent);  // Register receive event
  Serial.begin(9600);

  // Set solenoid pins as outputs
  pinMode(SOL1_PIN, OUTPUT);
  pinMode(SOL2_PIN, OUTPUT);
  pinMode(SOL3_PIN, OUTPUT);

  // Make sure solenoids are off initially
  digitalWrite(SOL1_PIN, LOW);
  digitalWrite(SOL2_PIN, LOW);
  digitalWrite(SOL3_PIN, LOW);

  Serial.println("Slave ready to receive solenoid commands.");
}

void loop() {
  // Nothing to do here. All handled by I2C receive event.
}

// Called when data is received from the master
void receiveEvent(int bytes) {
  if (bytes > 0) {
    uint8_t command = Wire.read();
    Serial.print("Received command: ");
    Serial.println(command);

    // Activate corresponding solenoid
    switch (command) {
      case 1:
        triggerSolenoid(SOL1_PIN);
        break;
      case 2:
        triggerSolenoid(SOL2_PIN);
        break;
      case 3:
        triggerSolenoid(SOL3_PIN);
        break;
      default:
        Serial.println("Unknown command.");
        break;
    }
  }
}

// Helper function to activate solenoid briefly
void triggerSolenoid(uint8_t pin) {
  digitalWrite(pin, HIGH);  // Turn solenoid ON
  delay(1000);              // Hold for 1 second
  digitalWrite(pin, LOW);   // Turn solenoid OFF
  Serial.print("Activated solenoid on pin ");
  Serial.println(pin);
}
