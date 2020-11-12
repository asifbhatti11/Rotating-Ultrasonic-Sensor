#include <Stepper.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A0 ,A1 ,15000);

int arraysize = 96;  //quantity of values to find the median (sample size). Needs to be an odd number
int rangevalue[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0};    

const int stepsPerRevolution = 96;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;         // number of steps the motor has taken
int distance;
void setup() 
{
  Serial.begin (9600); //SERIAL
}
void loop() 
{
  for(int i = 0; i < arraysize; i++)
  {
         myStepper.step(1);
         distance=ultrasonic.Ranging(CM);
         rangevalue[i] = distance;
         Serial.print(i);
         Serial.print("-");
         Serial.print(rangevalue[i]);
         Serial.print("  ");
           delay(1000/96); 
  }
Serial.println();
}
