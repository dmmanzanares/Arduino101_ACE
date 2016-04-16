/* Motor Demo
 * This sketch tests the motors by driving forward, turning right,
 * turning left and backward 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object
int speed = 60;  // speed setting (maximum is 255)

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  
  Serial.println("  Forward");
  car.motorsWrite(speed, speed);  // both motors forward
  delay(1000);
  car.stopMotors(); // stop both motors
  
  Serial.println("  Right");
  car.motorsWrite(speed, -1*speed); // left forward, right backward (negative)
  delay(1000);
  car.stopMotors(); // stop both motors
  
  Serial.println("  Left");
  car.motorsWrite(-1*speed, speed); // left backward (negative), right forward
  delay(1000);
  car.stopMotors(); // stop both motors
  
  Serial.println("  Backward");
  car.motorsWrite(-1*speed, -1*speed); // both motors backward (negative)
  delay(1000);
  car.stopMotors(); // stop both motors
}

void loop() {
  // put your main code here, to run repeatedly:

}
