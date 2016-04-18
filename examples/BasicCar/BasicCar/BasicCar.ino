//#include <BLE_Main.h>
#include <CarDemo.h>

CarDemo car;
int i = 0;

void setup() {
  Serial.begin(115200);
  car.setupCar();
  Serial.println("Car setup complete.");
  //car.motorLSkew = 1.0 // adjust for motor drift. 100% = straight
  //car.motorRSkew = 1.0 // adjust for motor drift. 100% = straight
  car.motorsWrite(255, 255);
  delay(1500);
  car.stopMotors();
}

void loop() {
  // put your main code here, to run repeatedly:
}
