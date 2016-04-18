/* Encoder Demo
 * This sketch tests the Proximity Sensor 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

int encoderLValue;
int encoderRValue;

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.setupEncoders();
  Serial.println("Turn the wheels and observe the encoder step count.");
}

void loop() {
  Serial.print("Left = ");
  Serial.print(encoderLValue);
  Serial.print(", Right = ");
  Serial.println(encoderRValue);
  delay(100);
}
