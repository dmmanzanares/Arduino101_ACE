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

//Motor Pin Assignments
const byte PWMA =  3; // PWM control pin (speed) for motor A
const byte PWMB =  9; // PWM control pin (speed) for motor B  NOTE it is pin 11 on the Shield we have to jump 9 and 11 for Arduino 101
const byte DIRA = 12; // Direction control pin for motor A
const byte DIRB = 13; // Direction control pin for motor B
const byte ENCA =  2; // Encoder for motor pin A
const byte ENCB =  8; // Encoder for motor pin B

//Buzzer Pin assignments
const byte PWMBUZZER = 5; // PWM control pin for horn/buzzer

//Servo Pin assignments
const byte PWMSERVO  = 6;  // PWM control pin (speed) for servo motor

//Proximity Pin Assignments
const byte PROXIMITY = A0; // Analog pin for distance sensed

//LED RGB Pin assignments
const byte LED       = 7;  // Only a Data pin is required on the addressable RGB LEDs


void setup() {
  Serial.begin(115200);
  delay(1000);
  promptCR_V3("Hit CR to setup components");

  //Curie Setup
  setupCurie();
  // Buzzer Setup
  setupBuzzer();
  // RGB LED Setup
  setupLED();
  // Motor Setup
  setupArdumoto();
  // Encoder Setup
  setupEncoders();
  // Servo Setup
  setupServo();
  // Proximity Setup
  setupProximity();
  Serial.println("\nWelcome to the Intel Maker Nation");
  Serial.println("  New Mexico Friends and Family 'Maker Racer' Event\n");
  Serial.println("  **Waiting for Double Tap detection to start Racer**\n");
  
  promptCR_V3("Hit CR to test");
  StartRacer();
}

void StartRacer()
{
  //waiting for Double Tap
  Serial.println("\n***Performing Racer Tests***\n");
  testBuzzer();
  testLED();
  clearLED();
  testArdumoto();
  testEncoders();
  testServo();
  testProximity();
  Serial.println("\n***Tests Complete***\n");
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

#define RESPONSE_TIMEOUT  4
#define RESPONSE_BUF_SIZE 5
boolean promptCR_V3(const char* aPrompt)
{
  bool result = false;

  int  timeout   = 1000 * RESPONSE_TIMEOUT; // Seconds between prompts
  int  bytecount = 0;
  char respBuffer[RESPONSE_BUF_SIZE];
tryAgain:
  // Display the prompt
  Serial.print(aPrompt);
  // Set an API timeout. When time expires, the prompt will happen again
  Serial.setTimeout(timeout);
  // The API will block until a <NL> is received or the timeout has occurred.
  // Data is expected to be followed by a <CR>,<NL>. Since all we expected is a CR,
  // a minimal data buffer is used.
  bytecount = Serial.readBytesUntil('\n', &respBuffer[0], RESPONSE_BUF_SIZE);
  // If no data, prompt again
  if (bytecount == 0) Serial.println("");
  if (bytecount == 0) goto tryAgain;

  // NL was spotted
  Serial.println("");
  result = true;
  return result;
} // promptCR_V3
