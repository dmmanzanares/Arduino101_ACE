#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.clearLED(); // turn all LEDs off
}

void loop() {
  if (car.checkObstacle(12)) {
    car.setLED(ALL_LEDS, RED);
    car.stopMotors();
    car.motorsWrite(-40, -40);
    delay(40);
    car.motorsWrite(40, -40);
    delay(100);
    car.stopMotors();
  } else {
    car.setLED(ALL_LEDS, GREEN);
    car.motorsWrite(40, 40);
  }
}
