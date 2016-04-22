#ifndef CARDEMO_H
#define CARDEMO_H
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include "colors.h"

class CarDemo {
	public:
		CarDemo();
        void setupCar();
		void testCar();
		void pauseCar();

		// Motor functions
		void setupMotors();
		void testMotors();
		void stopMotors();
		void motorsWrite(int speedL, int speedR);
		void motorsWriteStep(int speedL, int speedR, int stepsL, int stepsR);
		void fade(int speedL, int speedR);

		// LED functions and variables
		void setupLED();
		void clearLED();
		void brakeLED();
		void driveLED();
		void pauseLED();
		void leftLED();
		void rightLED();
		void startingLED();
		void setLED(int led, long color);
		void testLED();

		// Proximity sensor functions
		void setupProximity();
		void testProximity();
		float getRange();
		bool checkObstacle(int minDist);

		// Servo functions
		void setupServo();
		void testServo();
		void setServo(int angle);

        // Buzzer functions
		void setupBuzzer();
        void testBuzzer();
		void playSong(int *notes, int *durations, int numnotes);
        void playNote(int note, int duration);

        // Accelerometer functions
		void setupMotion();
        bool tilted();

        // Encoder functions
		void setupEncoders();

		// Class member variables
		float motorLSkew;
		float motorRSkew;

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
		//LED Pin assignment
		byte extLED = 0;  //this is the external LED to use without the RGB LEDs and cable

		private:
		Adafruit_NeoPixel strip;
		Servo servo;
};

void countL();
void countR();
extern int encoderLValue;
extern int encoderRValue;
extern int encoderLStopCount;
extern int encoderRStopCount;
extern int motorLSpeed;
extern int motorRSpeed;

extern int FULLSPEED;
extern int HALFSPEED;

#endif // CARDEMO_H
