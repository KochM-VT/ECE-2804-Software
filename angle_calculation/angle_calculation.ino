// ECE 2804 Audio Direction Finding Project
// Angle Calculation Code
// Written By: Michael Koch
// Last Update: 4/27/2020

const double MIC_DISTANCE = 0.055; //5.5 cm, the distance between the centers of the electret mics
const double RAD_TO_DEGREES = 57.2958; // Radian to degree conversion 
const int mic1_Pin = 3; // Pin for microphone 1 (measured from here)
const int mic2_Pin = 2; // Pin for microphone 2
const double SPEED_OF_SOUND = 343; // Speed of sound in m/s
const double MAX_TIMEDIFF = MIC_DISTANCE/SPEED_OF_SOUND; // Maximum time difference the two microphones can have
const double PERIOD = 0.001;
const double ONE_US = 0.000001;
const double NINETY_DEGREES = 90;

int startTime = 0; //Start Time for 
int difference = 0;
bool start = false; 
double angle = 0;
double difference_seconds;

void setup() {
  Serial.begin(115200); //Absolute highest BR possible on the Arduino
  attachInterrupt(digitalPinToInterrupt(mic1_Pin), ISR_Mic1, RISING);
  attachInterrupt(digitalPinToInterrupt(mic2_Pin), ISR_Mic2, RISING);
}

void ISR_Mic1() 
{
  start = true;  
  startTime = micros();
}

void ISR_Mic2()
{
  if (start)
  {
    difference = micros() - startTime;
    start = false;
  }
  
}

void loop() 
{

    difference_seconds = difference * ONE_US;

    if (difference_seconds > MAX_TIMEDIFF)
    {
      difference_seconds = PERIOD - difference_seconds;
      angle = 180 - (acos((SPEED_OF_SOUND*difference_seconds)/MIC_DISTANCE)*RAD_TO_DEGREES);
    }
    else
    {
      angle = acos((SPEED_OF_SOUND*difference_seconds)/MIC_DISTANCE)*RAD_TO_DEGREES;
    }
    Serial.println(angle);

}
