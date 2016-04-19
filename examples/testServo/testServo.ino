/* Proximity Sensor/Servo Demo
 * This sketch uses the servo to scan with the proximity sensor 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();   // setup all sensors and motors
  car.setupServo(); // Enable servo motor (disabled by default)

  Serial.println("  Moving servo from 30 to 150");
  int pos;
  float range;

  // Scan left-to-right and back
  // goes from 30 degrees to 150 degrees in steps of 1 degree
  for (pos = 30; pos <= 150; pos += 1) 
  {
    car.setServo(pos);       // tell servo to go to position in variable 'pos'
    delay(25);               // waits 15ms for the servo to reach the position
    range = car.getRange();  // get proximity sensor range
    Serial.print(pos);
    Serial.print(", ");
    Serial.println(range);
  }
  // goes from 150 degrees to 30 degrees in steps fo 1 degree
  Serial.println("  Moving servo from 150 to 30");
  for (pos = 150; pos >= 30; pos -= 1) 
  {
    car.setServo(pos);       // tell servo to go to position in variable 'pos'
    delay(25);               // waits 15ms for the servo to reach the position
    range = car.getRange();  // get proximity sensor range
    Serial.print(pos);
    Serial.print(", ");
    Serial.println(range);
  }
}

void loop() {
  // put your main code here, to run repeatedly
}
