#include "CarDemo.h"
/*
  Intel Maker Nation presents a Family and Friends Event
  Beginner “Maker Racer: Speedway”
  Participants will race for maker victory.
  Teams will assemble and code their Racer using the Sparkfun Shadow Chassis and Ardumoto shield and the Adruino 101.
  Intermediate “Maker Racer: Supernationals”
  Participants will dazzle racing fans with their enhanced racers while racing for maker victory.
  Teams will assemble and code their Racer using the Sparkfun Shadow Chassis and Ardumoto shield, the Adruino 101 and trick their ride with lights and sound.
  Advanced “Maker Racer: Road Rally”
  Participants will amaze audiences maneuvering their racer through an obstacle course to achieve maker victory.
  Teams will assemble and code their Racer using the Sparkfun Shadow Chassis and Ardumoto shield, the Adruino 101, add lights and sound and a servo controlled proximity sensor.

  Special Thanks to:
  Intel NM Makers: A. Barnes, D. McCulley, D. Manzanares, J. Sholar, R. Mcinnis, B. Baltz, N. Paz
  NM Site Personnel: T. Marsh, R. Eppes
*/
// included libraries

#include "CarDemo.h"
#include <Arduino.h>

CarDemo::CarDemo() {
  // Serial.begin(115200);
  // delay(2000);
  // Serial.println("\nWelcome to the Intel Maker Nation");
  // Serial.println("  New Mexico Friends and Family 'Maker Racer' Event\n");
  // Serial.println("  **Waiting for car rotation to start Racer**\n");
  setupMotors();
  setupLED();
  //Curie Setup
  //setupMotion();
  // Buzzer Setup
  //setupBuzzer();
  // RGB LED Setup
  //setupLED();
  // Motor Setup
  //setupArdumoto();
  // Encoder Setup
  //setupEncoders();
  // Servo Setup
  //setupServo();
  // Proximity Setup
  //setupProximity();

  //pauseLED(); // turn on LEDs in 'paused' (blue) mode
  
  // while (!tilted()) {}
  // startingLED(); // indicate car is starting
  // Serial.println("\n\nCar activated - starting test.\n");
  // clearLED();
  // StartRacer();
}

void CarDemo::testCar()
{
  //waiting for Double Tap
  //Serial.println("\n***Performing Racer Tests***\n");
  //testBuzzer();
  testLED();
  //clearLED();
  testMotors();
  //testEncoders();
  //testServo();
  //testProximity();
  //Serial.println("\n***Tests Complete***\n");
}
