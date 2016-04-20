/* Basic Car Demo
 * This sketch drives the car straight for some time 
 */
#include <CarDemo.h>

CarDemo car;

void setup() {
  Serial.begin(115200);
  car.setupCar();             // Initialize car settings and pause car
                              // Tilt the car to continue
  Serial.println("Car setup complete.");
  car.motorsWrite(255, 255);  // full speed ahead!!
  delay(3000);
  car.stopMotors();           // stop motors after 3 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
}
