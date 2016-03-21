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
#include "Car.h"
#include "CurieIMU.h"
#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//#include <SharpIR.h>

// Motor definitions to make life easier:
const byte MOTOR_A = 0;
const byte MOTOR_B = 1;
// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
const byte CW = 0;
const byte CCW = 1;
//Motor Pin Assignments
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 9;  // PWM control (speed) for motor B  NOTE it is pin 11 on the Shield we have to jump 9 and 11 for Arduino 101
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B
const byte ENCA = 2;  // Encoder for motor A
const byte ENCB = 8;  // Encoder for motor B
//Encoder definitions
int encorderAValue=0;
int encorderBValue=0;

//Buzzer Pin assignments
const byte PWMBUZZER = 5; // PWM control for horn/buzzer
//Servo Pin assignments
const byte PWMSERVO = 6;  // PWM control (speed) for servo motor
// Servo definitions
Servo myservo;  // create servo object to control a servo  
int pos = 0;    // variable to store the servo position 

//Proximity Pin Assignments
const byte PROXIMITY = A0; //Analog pin for distance sensed
// Sharp IR distance sensor
// SharpIR sharp(PROXIMITY, 25, 93, 430);

//LED RGB Pin assignments
const byte LED = 7;        // Only a Data pin is required on the addressable RGB LEDs
const byte NUMPIXELS = 4;  // number of RGB LEDs used
// Addressable RGB LED definitions...like a NeoPixel
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
// IMPORTANT: To reduce LED burnout risk, add 0.1 uF capacitor across pixel power leads, 
// add 50 - 100 Ohm resistor on first pixel's data input
// Avoid connecting on a live circuit...if you must, connect GND first.

void setup() {
Serial.begin(9600);
//Curie Setup
  setupCurie();
// Motor Setup
  setupArdumoto(); 
// Encoder Setup
  setupEncoders();
// Buzzer Setup
  setupBuzzer();
// RGB LED Setup
  setupLED();
// Servo Setup
  setupServo();
// Proximity Setup
  setupProximity();

 testBuzzer();
 testLED();
 testServo();
 testProximity();
 testArdumoto();
 testEncoders();
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
