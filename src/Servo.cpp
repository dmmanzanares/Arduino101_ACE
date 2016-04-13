#include <Servo.h>
#include "CarDemo.h"
//Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

/* adapted from Sevo Sweep example
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

void CarDemo::setupServo()
{
  //Serial.println("Servo Setup...");
  servo.attach(SERVO);  // attaches the servo on PWM pin to the servo object
  //Serial.println("  ...Servo ready for control");
}

void CarDemo::testServo()
{
  //Serial.println("Servo Test");
  servo.write(90);       // start at 90
  delay(30);
  //Serial.println("  Moving servo from 30 to 150");
  for (pos = 30; pos <= 150; pos += 1) // goes from 30 degrees to 150 degrees in steps of 1 degree
  {
    servo.write(pos);       // tell servo to go to position in variable 'pos'
    delay(15);                // waits 15ms for the servo to reach the position
  }
  //Serial.println("  Moving servo from 150 to 30");
  for (pos = 150; pos >= 30; pos -= 1) // goes from 150 degrees to 30 degrees in steps fo 1 degree
  {
    servo.write(pos);       // tell servo to go to position in variable 'pos'
    delay(15);                // waits 15ms for the servo to reach the position
  }
  servo.write(90);          // end at 90
  delay(30);
}

