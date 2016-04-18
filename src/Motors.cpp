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
int FULLSPEED = 255;
int HALFSPEED = 127;

// Motor definitions to make life easier:
// const byte MOTOR_A = 0;
// const byte MOTOR_B = 1;
// const byte MOTORS  = 2;


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
  //Serial.println("  ...Motors ready for control");
}

void CarDemo::testMotors()
{
  int speed = 127;
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
  digitalWrite(MOTORL, LOW);
  digitalWrite(MOTORR, LOW);
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
  // else if (motor == MOTORS)
  // {
    // digitalWrite(DIRL, dir);
    // digitalWrite(DIRR, dir);
  // }
  //fadein(motor, spd);
  speedL = abs(speedL * motorLSkew);
  speedR = abs(speedR * motorRSkew);
  Serial.println(speedL);
  Serial.println(speedR);
  analogWrite(MOTORL, speedL);
  analogWrite(MOTORR, speedR);
  //delay(mdelay); //run motors for this long
}

void CarDemo::motorsWriteStep(int speedL, int speedR, int stepsL, int stepsR)
{
	encoderLStopCount = stepsL;
    encoderRStopCount = stepsR;
	encoderLValue = 0;
    encoderRValue = 0;
	motorsWrite(speedL, speedR);
}

// void fadein(byte motor, byte spd)
// {
  // // fade in from min to desired spd in increments of 5 points:
  // for (int fadeValue = 0 ; fadeValue <= spd; fadeValue += 5)
  // {
    // // sets the value (range from 0 to 255):
    // if (motor == MOTOR_A)
    // {
      // analogWrite(MOTORL, fadeValue);
    // }
    // else if (motor == MOTOR_B)
    // {
      // analogWrite(MOTORR, fadeValue);
    // }
    // else if (motor == MOTORS)
    // {
      // analogWrite(MOTORL, fadeValue);
      // analogWrite(MOTORR, fadeValue);
    // }
    // // wait for 30 milliseconds to see the dimming effect
    // delay(30);
  // }
// }
// void forward(byte spd, int mdelay)
// {
  // // Drive motor A  and B at various speeds, for a specified length of time
  // driveMotors(MOTORS, CW, spd, mdelay);  // Set motor A and B to CW at spd for mdelay time
// }

// void backward(byte spd, int mdelay)
// {
  // // Drive motor A  and B at various speeds, for a specified length of time
  // driveMotors(MOTORS, CCW, spd, mdelay);  // Set motor A and B to CCW at spd for mdelay time
// }
// void right(byte spd, int mdelay)
// {
  // // Drive motor A  at various speeds, for a specified length of time
  // driveMotors(MOTOR_A, CW, spd, mdelay);  // Set motor A to CW at spd for mdelay time
// }

// void left(byte spd, int mdelay)
// {
  // // Drive motor B at various speeds, for a specified length of time
  // driveMotors(MOTOR_B, CW, spd, mdelay);  // Set motor B to CW at spd for mdelay time
// }
//} // namespace
