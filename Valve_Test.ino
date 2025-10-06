int solenoidPin1 = 2; //This is the output pin on the Arduino we are using
int solenoidPin2 = 3; //This is the output pin on the Arduino we are using
int solenoidPin3 = 4; //This is the output pin on the Arduino we are using

void setup() {
// put your setup code here, to run once:
pinMode(solenoidPin1, OUTPUT); //Sets the pin as an output
pinMode(solenoidPin2, OUTPUT); //Sets the pin as an output
pinMode(solenoidPin3, OUTPUT); //Sets the pin as an output
}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(solenoidPin1, HIGH); //Switch Solenoid ON
delay(1000); //Wait 1 Second
digitalWrite(solenoidPin1, LOW); //Switch Solenoid OFF
delay(1000); //Wait 1 Second

digitalWrite(solenoidPin2, HIGH); //Switch Solenoid ON
delay(1000); //Wait 1 Second
digitalWrite(solenoidPin2, LOW); //Switch Solenoid OFF
delay(1000); //Wait 1 Second

digitalWrite(solenoidPin3, HIGH); //Switch Solenoid ON
delay(1000); //Wait 1 Second
digitalWrite(solenoidPin3, LOW); //Switch Solenoid OFF
delay(1000); //Wait 1 Second
}