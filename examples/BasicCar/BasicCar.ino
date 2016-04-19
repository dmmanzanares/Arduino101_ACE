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
  delay(1500);                
  car.stopMotors();           // stop motors after 1.5 seconds
}

void loop() {
  // put your main code here, to run repeatedly:
}
