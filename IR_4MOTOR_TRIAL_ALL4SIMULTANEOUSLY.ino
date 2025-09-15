#include <IRremote.hpp>

int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define PUL1 8  // Pulse pin
#define DIR1 9  // Direction pin
#define PUL2 5  // Pulse pin
#define DIR2 6  // Direction pin
#define PUL3 11  // Pulse pin
#define DIR3 12  // Direction pin
#define PUL4 2  // Pulse pin
#define DIR4 3  // Direction pin

void setup() {

  Serial.begin(9600);
  irrecv.begin(RECV_PIN); // Start the receiver
  
  pinMode(PUL1, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(PUL2, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PUL3, OUTPUT);
  pinMode(DIR3, OUTPUT);
  pinMode(PUL4, OUTPUT);
  pinMode(DIR4, OUTPUT);

}
  
void loop() {

  if (irrecv.decode())
    {
      Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
      //Serial.println(irrecv.decodedIRData.address, HEX);
      //Serial.println(irrecv.decodedIRData.command, HEX);

      irrecv.resume(); // Receive the next value
      
      //get start value
      if (irrecv.decodedIRData.decodedRawData == 0xF30CFF00) // button 1
      {

        Serial.println("running"); 
   
  // Rotate motor clockwise
  digitalWrite(DIR1, HIGH); 
  digitalWrite(DIR2, HIGH); 
  digitalWrite(DIR3, HIGH);
  digitalWrite(DIR4, HIGH);
  for (int i = 0; i < 3200; i++) { // Adjust for desired steps
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    digitalWrite(PUL3, HIGH);
    digitalWrite(PUL4, HIGH);
    delayMicroseconds(500); // Adjust speed
    
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW);
    delayMicroseconds(500);
  }
  
  delay(1000); // Pause before reversing
  
  // Rotate motor counterclockwise
  digitalWrite(DIR1, LOW); 
  digitalWrite(DIR2, LOW); 
  digitalWrite(DIR3, LOW);
  digitalWrite(DIR4, LOW);
  for (int i = 0; i < 3200; i++) {
    digitalWrite(PUL1, HIGH);
    digitalWrite(PUL2, HIGH);
    digitalWrite(PUL3, HIGH);
    digitalWrite(PUL4, HIGH);
    delayMicroseconds(500);
    
    digitalWrite(PUL1, LOW);
    digitalWrite(PUL2, LOW);
    digitalWrite(PUL3, LOW);
    digitalWrite(PUL4, LOW);
    delayMicroseconds(500);
  }
  
  delay(1000); // Pause before looping

    }
    }

}
