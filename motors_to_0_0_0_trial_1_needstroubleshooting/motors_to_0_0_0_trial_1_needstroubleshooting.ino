// This code works to bring the cubesat back to (0,0,0), however, if you try to press one of the buttons to give it slack after bringing it back to (0,0,0), say you press button 1 again, it will keep trying to reel the cubesat in instead of giving it slack again, so it needs to be troubleshooted.
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 13
// Motor pins
#define PUL1 8
#define DIR1 9
#define PUL2 5
#define DIR2 6
#define PUL3 11
#define DIR3 12
#define PUL4 2
#define DIR4 3

// Motor states
bool motor1Running = false;
bool motor2Running = false;
bool motor3Running = false;
bool motor4Running = false;

// Absolute positions
long pos1 = 0;
long pos2 = 0;
long pos3 = 0;
long pos4 = 0;

// IR codes
#define BTN1 0xF30CFF00 //button 1 on remote
#define BTN2 0xE718FF00 //button 2 on remote
#define BTN3 0xA15EFF00 //button 3 on remote
#define BTN4 0xF708FF00 //button 4 on remote
#define BTN_RESET 0xE31CFF00  //button 5 on remote

void setup() {
    Serial.begin(9600);
    IrReceiver.begin(IR_RECEIVE_PIN);

    pinMode(PUL1, OUTPUT);
    pinMode(DIR1, OUTPUT);
    digitalWrite(DIR1, LOW);    

    pinMode(PUL2, OUTPUT);
    pinMode(DIR2, OUTPUT);
    digitalWrite(DIR2, LOW);
    
    pinMode(PUL3, OUTPUT);
    pinMode(DIR3, OUTPUT);
    digitalWrite(DIR3, LOW);

    pinMode(PUL4, OUTPUT);
    pinMode(DIR4, OUTPUT);
    digitalWrite(DIR4, LOW);

    Serial.println("Motors initialized. Origin is (0, 0, 0, 0).");
}

void loop() {
        
    if (IrReceiver.decode()) {
        auto code = IrReceiver.decodedIRData.decodedRawData; //rawData_
        Serial.print(code);

        Serial.println(code, HEX); // Print "old" raw data
        IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
        IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
        IrReceiver.resume(); // Enable receiving of the next value    

        if (code == BTN1) {
            motor1Running = !motor1Running;
            if (!motor1Running) {
                Serial.print("Motor 1 stopped. Current position: ");
                Serial.println(pos1);
            }
        }
        else if (code == BTN2) {
            motor2Running = !motor2Running;
            if (!motor2Running) {
                Serial.print("Motor 2 stopped. Current position: ");
                Serial.println(pos2);
            }
        }
        else if (code == BTN3) {
            motor3Running = !motor3Running;
            if (!motor3Running) {
                Serial.print("Motor 3 stopped. Current position: ");
                Serial.println(pos3);
            }
        }
        else if (code == BTN4) {
            motor4Running = !motor4Running;
            if (!motor4Running) {
                Serial.print("Motor 4 stopped. Current position: ");
                Serial.println(pos4);
            }
        }
        else if (code == BTN_RESET) {
            Serial.println("Returning all motors to zero position...");
            goToZero(PUL1, DIR1, pos1);
            goToZero(PUL2, DIR2, pos2);
            goToZero(PUL3, DIR3, pos3);
            goToZero(PUL4, DIR4, pos4);
            pos1 = 0;
            pos2 = 0;
            pos3 = 0;
            pos4 = 0;
            Serial.println("All motors returned to (0, 0, 0, 0)");
        }
    }

    // Run motors if active
    if (motor1Running) pos1 += pulseMotor(PUL1, 300);
    if (motor2Running) pos2 += pulseMotor(PUL2, 300);
    if (motor3Running) pos3 += pulseMotor(PUL3, 300);
    if (motor4Running) pos4 += pulseMotor(PUL4, 300);
}

// Single pulse = 1 step
int pulseMotor(int PUL, int time_btwn) {
    digitalWrite(PUL, HIGH);
    delayMicroseconds(time_btwn);
    digitalWrite(PUL, LOW);
    delayMicroseconds(time_btwn);
    return 1;
}

// Go back to zero position
void goToZero(int PUL, int DIR, long &pos) {
    if (pos == 0) return; // Already at zero

    bool reverseDir = (pos > 0); // Go back if moved forward
    digitalWrite(DIR, reverseDir ? HIGH : LOW); // Reverse direction

    for (long i = 0; i < abs(pos); i++) {
        digitalWrite(PUL, HIGH);
        delayMicroseconds(300);
        digitalWrite(PUL, LOW);
        delayMicroseconds(300);
    }
}
