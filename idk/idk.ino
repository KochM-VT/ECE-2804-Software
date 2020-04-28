// This number is subject to change depending on final product
// This is a placeholder
double btwnSpeakers = .055;
int micA = 0;
int micB = 0;
// This is speed/frequency assuming ideal conditions
double wavelength = 0.343;
double timeone;
double timetwo;
double diff;
double d;
double argument;
double rad;
double angle;
double conversion = 180/PI;
int mic1Pin = 13;
int mic2Pin = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(mic1Pin, INPUT);
  pinMode(mic2Pin, INPUT);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  // This part will change depending on how we interface with the circuit
  if (micA > 1)
  {
    if (digitalRead(mic1Pin) == HIGH)
    {
      timeone = micros();
      micA = 1;
    }    
  }
  if (micB > 1)
  {
    if (digitalRead(mic2Pin) == HIGH)
    {
      timetwo = micros();
      micB = 1;
    }
  }
  // This is the math that works and we will create a diagram labeling microphone A and B
  // It accurately determines the angle we just need to figure out a good way to figure out
  // the time that the wave hit each of microphones.
  if (timeone > timetwo)
  {
    diff = timeone - timetwo;
    d = diff * wavelength;
    argument = d/btwnSpeakers;
    rad = acos(argument);
    angle = rad * conversion;
    Serial.println("The speakers is closer to microphone A");
    Serial.print("The speaker is located ");
    Serial.print(angle);
    Serial.println(" degrees relative to microphone B.");
  }
  else if (timetwo > timeone) 
  {
    diff = timetwo - timeone;
    d = diff * wavelength;
    argument = d/btwnSpeakers;
    rad = acos(argument);
    angle = rad * conversion;
    Serial.println("The speakers is closer to microphone B");
    Serial.print("The speaker is located ");
    Serial.print(angle);
    Serial.println(" degrees relative to microphone A.");
  }
    
}
