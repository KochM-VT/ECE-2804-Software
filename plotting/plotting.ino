// This code is meant to take in the data from an analog input.
// It will then put the data in a form that can then be plotted.
// This is in order to prove that the interfacing with the arduino is working properly.
// Written by: Benjamin Blitt
// Date: April 6, 2020
// ECE-2804
// Audio Direction Project

// Initializing the analog input pin that will take in the signal and the value that it will be used to store the data

int sensorPin = A0;
int sensorValue = 0;
int voltageValue = 0;
int sensorPintwo = A1;
int sensorValuetwo = 0;
int voltageValuetwo = 0;


void setup() {
  // put your setup code here, to run once:
  // Initialize communcation with computer
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Read the value from the circuit into sensorValue;
  sensorValue = analogRead(sensorPin);
  // Convert the value read to the voltage value as seen by the arduino
  voltageValue = map(sensorValue, 0, 1023, 0, 5);

  // Read the value from the circuit into sensorValue;
  sensorValuetwo = analogRead(sensorPintwo);
  // Convert the value read to the voltage value as seen by the arduino
  voltageValuetwo = map(sensorValuetwo, 0, 1023, 0, 5);

  // Print out the input value after it has been converted to the 0 to 5  scale.
  Serial.println(voltageValue);
  Serial.print(",");
  Serial.println(voltageValuetwo);
  Serial.print(" ");

  // Delay before the next reading to allow the system to not be overloaded.
  delay(2);

}

