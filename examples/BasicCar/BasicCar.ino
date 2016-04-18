//#include <BLE_Main.h>
#include <CarDemo.h>

CarDemo car;
int i = 0;

void setup() {
  Serial.begin(115200);
  car.setupCar();
  Serial.println("Car setup complete.");
  car.testLED();
  car.motorsWrite(60, 60);
  delay(1500);
  car.stopMotors();
  car.testServo();
  car.testBuzzer();
  //car.testCar();
  car.testProximity();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(i++);
  //delay(1000);
}
