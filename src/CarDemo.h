#ifndef CARDEMO_H
#define CARDEMO_H
#include <Adafruit_NeoPixel.h>
//namespace CarDemo {
//#define ENABLE_SERVO
//#define ENABLE_PROXIMITY
//#define ENABLE_MOTORSHIELD
//#define ENABLE_BUZZER
//#define ENABLE_TAP
//#define ENABLE_ENCODER
//#define ENABLE_LED

class CarDemo {
	public:
		CarDemo();
		void testCar();
		
		// Motor functions
		void setupMotors();
		void testMotors();
		void stopMotors();
		void motorsWrite(int speedL, int speedR);
		
		// LED functions and variables  
		void setupLED();
		void clearLED();
		void brakeLED();
		void driveLED();
		void pauseLED();
		void leftLED();
		void rightLED();
		void startingLED();
		void testLED();
		
	private:		
		//Motor Pin Assignments
		byte MOTORL =  3; // PWM control pin (speed) for left motor 
		byte MOTORR =  9; // PWM control pin (speed) for right motor   NOTE it is pin 11 on the Shield we have to jump 9 and 11 for Arduino 101
		byte DIRL   = 12; // Direction control pin for motor A
		byte DIRR   = 13; // Direction control pin for motor B
		byte ENCL   =  2; // Encoder for motor pin A
		byte ENCR   =  8; // Encoder for motor pin B

		//Buzzer Pin assignments
		byte BUZZER = 5; // PWM control pin for horn/buzzer

		//Servo Pin assignments
		byte SERVO  = 6;  // PWM control pin (speed) for servo motor

		//Proximity Pin Assignments
		byte PROXIMITY = A0; // Analog pin for distance sensed

		//LED RGB Pin assignments
		byte LED       = 7;  // Only a Data pin is required on the addressable RGB LEDs
		
		Adafruit_NeoPixel strip;
};
//} //namespace

//using namespace CarDemo;

#endif // CARDEMO_H