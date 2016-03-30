//#define ENABLE_SERVO
//#define ENABLE_PROXIMITY
//#define ENABLE_MOTORSHIELD
//#define ENABLE_BUZZER
#define ENABLE_TAP
//#define ENABLE_ENCODER
#define ENABLE_LED

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
