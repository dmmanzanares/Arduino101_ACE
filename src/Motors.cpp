#include "CarDemo.h"
//namespace CarDemo {
/* Adapted from Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this sketch!

  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed], [mdelay]) --
      Drive [motor] (0 for A, 1 for B, 2 for both) in [direction] (0 or 1) at a [speed] between 0 and 255, for length of time [mdelay].
    stopArdumoto([motor]) -- Stop driving both motors
      For ease of coding the functions have been created: forward, backward, right and left.  Each require speed and duration.
      To reduce the surge current on the battery...a fadein function has been created, to fade in from 0 to speed requested.
  setupArdumoto() is called in the setup().
  The testArdumoto() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
const byte CW  = 0;
const byte CCW = 1;

// common motor speeds
int FULLSPEED = 255;
int HALFSPEED = 127;

// Global variables for current motor speed
int motorLSpeed;
int motorRSpeed;

// setupArdumoto initialize all pins
void CarDemo::setupMotors()
{
  //Serial.print("Setup Ardumoto Shield...");
  // All pins should be setup as outputs:
  pinMode(MOTORL, OUTPUT);
  pinMode(MOTORR, OUTPUT);
  pinMode(DIRL, OUTPUT);
  pinMode(DIRR, OUTPUT);
  // Initialize all pins as low:
  digitalWrite(MOTORL, LOW);
  digitalWrite(MOTORR, LOW);
  digitalWrite(DIRL, LOW);
  digitalWrite(DIRR, LOW);
  motorLSpeed = 0;
  motorLSpeed = 0;
}

void CarDemo::testMotors()
{
  int speed = HALFSPEED;
  Serial.println("Motor Test");
  Serial.println("  Forward");
  motorsWrite(speed, speed);
  delay(2000);
  Serial.println("  Right");
  motorsWrite(speed, -1*speed);
  delay(2000);
  Serial.println("  Left");
  motorsWrite(-1*speed, speed);
  delay(2000);
  Serial.println("  Backward");
  motorsWrite(-1*speed, -1*speed);
  delay(2000);
  stopMotors();  
}

// stopMotors makes a motor stop
void CarDemo::stopMotors()
{
  analogWrite(MOTORL, 0);
  analogWrite(MOTORR, 0);
  // Update global speed variables
  motorLSpeed = 0;   
  motorLSpeed = 0;
}

// driveMotors drives 'motor' in 'dir' direction at 'spd' speed
void CarDemo::motorsWrite(int speedL, int speedR)
{
  if (speedL < 0)
  {
    digitalWrite(DIRL, CCW); // reverse
  }
  else
  {
    digitalWrite(DIRL, CW); // forward
  }
  if (speedR < 0)
  {
    digitalWrite(DIRR, CW); // reverse
  }
  else
  {
    digitalWrite(DIRR, CCW); // forward 
  }

  speedL = abs(speedL * motorLSkew);
  speedR = abs(speedR * motorRSkew);
  Serial.println(speedL);
  Serial.println(speedR);
  //analogWrite(MOTORL, speedL);
  //analogWrite(MOTORR, speedR);
  fade(speedL, speedR);  // move to new speeds in steps
  motorLSpeed = speedL;  // update global L speed variable
  motorRSpeed = speedR;  // update global R speed variable
}

void CarDemo::motorsWriteStep(int speedL, int speedR, int stepsL, int stepsR)
{
	encoderLStopCount = stepsL;
    encoderRStopCount = stepsR;
	encoderLValue = 0;
    encoderRValue = 0;
	motorsWrite(speedL, speedR);
}

void CarDemo::fade(int speedL, int speedR)
{
  // step amount to increase/decrease from current speeds
  int diffL = (speedL - motorLSpeed) / 50;  // L step amount
  int diffR = (speedR - motorRSpeed) / 50;  // R step amount
  int spL = motorLSpeed;  // set initial step speed to current speed
  int spR = motorRSpeed;  // set initial step speed to current speed
  for (int i = 0; i < 50; i++)
  {
    spL += diffL;
    spR += diffR;
    analogWrite(MOTORL, spL);
    analogWrite(MOTORR, spR); 
    //delay(25);
  }
  analogWrite(MOTORL, speedL);  // ensure final speed is set
  analogWrite(MOTORR, speedR);  // ensure final speed is set
}
