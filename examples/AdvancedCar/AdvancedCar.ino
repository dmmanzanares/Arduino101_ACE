#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.setupServo();  // enable the servo
  car.setupEncoders();
  car.motorLSkew = 0.95; // slow up the left wheel a bit (95% of right speed)
  //car.motorRSkew = 0.95; // adjust for motor drift. 100% = straight
  car.clearLED(); // turn all LEDs off
  //car.setServo(90);
}

void loop() {
  int carspeed = 180;
  if (car.checkObstacle(14)) {
    car.setLED(ALL_LEDS, RED);
    car.stopMotors();
    delay(20);
    car.motorsWrite(-1*carspeed, -1*carspeed); // back up a little bit
    delay(20);
    car.motorsWrite(carspeed, -1*carspeed);  // turn right
    delay(20);
    car.stopMotors();
  } else {
    car.setLED(ALL_LEDS, GREEN);
    car.motorsWrite(carspeed, carspeed);
  }
}
