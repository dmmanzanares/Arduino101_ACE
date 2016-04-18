#include <CarDemo.h>

CarDemo car;

void setup() {
  Serial.begin(115200);
  car.setupCar();
  delay(2000);
  car.playCharge();

}

void loop() {
  // put your main code here, to run repeatedly:

}
