<<<<<<< Updated upstream
void setup() {
  // put your setup code here, to run once:

=======
// This code is meant to take in the data from an analog input.
// It will then put the data in a form that can then be plotted.
// This is in order to prove that the interfacing with the arduino is working properly.
// Written by: Benjamin Blitt, Michael Koch
// Date Last Updated: April 6, 2020
// ECE-2804
// Audio Direction Project

// Initializing the analog input pins that will take in the signal and the value that it will be used to store the data

int sensorPin = A0;
int sensorValue = 0;
double voltageValue = 0;
int sensorPintwo = A1;
int sensorValuetwo = 0;
double voltageValuetwo = 0;


void setup() {
  // Initialize communcation with computer
  Serial.begin(9600);
>>>>>>> Stashed changes
}

void loop() {

<<<<<<< Updated upstream
=======
  // Read the value from the circuit into sensorValue;
  sensorValue = analogRead(sensorPin);
  // Convert the value read to the voltage value as seen by the arduino
  voltageValue = voltagemap(sensorValue, 0, 1023, 0, 5);

  // Read the value from the circuit into sensorValue;
  sensorValuetwo = analogRead(sensorPintwo);
  // Convert the value read to the voltage value as seen by the arduino
  voltageValuetwo = voltagemap(sensorValuetwo, 0, 1023, 0, 5);

  // Print out the input value after it has been converted to the 0 to 5  scale. Exportable to CSV.
  Serial.print(voltageValue);
  Serial.print(",");
  Serial.print(voltageValuetwo);
  Serial.println("");

}

// Custom voltage map function: does what the Arduino map() function does, but with doubles as a datatype.
double voltagemap(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
>>>>>>> Stashed changes
}
