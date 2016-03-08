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
Site Personnel: T. Marsh, R. Eppes
*/
// included libraries
#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include "Car.h"

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1
// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define CW  0
#define CCW 1

//Motor Pin Assignments
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 9; // PWM control (speed) for motor B  NOTE it is pin 11 on the Shield we have to jump 9 and 11 for Arduino 101
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B
const byte ENCA = A0;
const byte ENCB = A1;
//LED RGB Pin assignments
const byte LED = 7; // Only a Data pin is required on the addressable RGB LEDs
//Buzzer Pin assignments
const byte PWMHORN = 6; // PWM control for horn/buzzer
//Servo Pin assignments
const byte PWMSERVO = 5; // PWM control (speed) for servo motor
//Proximity Pin Assignments
const byte PROXIMITY = A2; //Analog pin for distance sensed

// Addressable RGB LED definitions...like a NeoPixel
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
int NUMPIXELS = 4;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce LED burnout risk, add 0.1 uF capacitor across pixel power leads, 
// add 50 - 100 Ohm resistor on first pixel's data input
// Avoid connecting on a live circuit...if you must, connect GND first.

// Servo definitions
Servo myservo;  // create servo object to control a servo  
int pos = 0;    // variable to store the servo position 

void setup() {
// Motor Setup
  setupArdumoto(); 
// Buzzer Setup
  setuphorn();
//RGB LED Setup
  setupLED();
//Servo Setup
  setupServo();

 testhorn();
 testLED();
 testServo();
 testProximity();
 testArdumoto();
}

void loop() 
{
// Beginner “Maker Racer: Speedway”
//  Participants will race for maker victory.  

// Intermediate “Maker Racer: Supernationals”
//  Participants will dazzle racing fans with their enhanced racers while racing for maker victory.  

//Advanced “Maker Racer: Road Rally”
//  Participants will amaze audiences maneuvering their racer through an obstacle course to achieve maker victory.  

}
