/* Proximity Sensor/Servo Demo
 * This sketch uses the servo to scan with the proximity sensor 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();   // setup all sensors and motors
  car.setupServo(); // Enable servo motor (disabled by default)

  int pos;

  // Scan left-to-right and back
  // goes from 30 degrees to 150 degrees in steps of 1 degree
  Serial.println("  Moving servo from 30 to 150");
  for (pos = 30; pos <= 150; pos += 1) 
  {
    car.setServo(pos);       // tell servo to go to position in variable 'pos'
    delay(25);               // waits 25ms for the servo to reach the position
  }
  // goes from 150 degrees to 30 degrees in steps fo 1 degree
  Serial.println("  Moving servo from 150 to 30");
  for (pos = 150; pos >= 30; pos -= 1) 
  {
    car.setServo(pos);       // tell servo to go to position in variable 'pos'
    delay(25);               // waits 25ms for the servo to reach the position
  }
  Serial.println("  Moving servo to 90");
  car.setServo(pos);         // center the servo
  delay(25);
}

void loop() {
  // put your main code here, to run repeatedly
}
