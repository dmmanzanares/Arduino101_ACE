//#include <BLE_Main.h>
#include <CarDemo.h>

CarDemo car;
int i = 0;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Hi0");
  car.setupServo();
  
  //car.setupMotors();
  //car.motorsWrite(100, 100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i++);
  delay(1000);
}
