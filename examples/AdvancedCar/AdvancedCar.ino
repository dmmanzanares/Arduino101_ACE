/* Advanced Car Demo
 * This sketch drives the car forward until obstacle is detected and then
 * maneuvers until the path is free. 
 */
 #include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();        // setup all sensors and motors
  car.setupServo();      // enable the servo
  car.setupEncoders();
  car.motorLSkew = 0.95; // slow up the left wheel a bit (95% of right speed)
  //car.motorRSkew = 0.95; // adjust for motor drift. 100% = straight
  car.clearLED();        // turn all LEDs off
  //car.setServo(90);
}

void loop() {
  int carspeed = 180;           // 180/255 PWM speed(70% duty cycle) 
  if (car.checkObstacle(14)) {  // check for obstacle
    car.setLED(ALL_LEDS, RED);  // turn LEDs red if path is blocked
    car.stopMotors();           // stop motors
    delay(20);
    car.motorsWrite(-1*carspeed, -1*carspeed); // back up a little bit
    delay(20);
    car.motorsWrite(carspeed, -1*carspeed);    // turn right
    delay(20);
    car.stopMotors();           // stop motors
  } else {
    car.setLED(ALL_LEDS, GREEN);          // if path is clear turn LEDs green
    car.motorsWrite(carspeed, carspeed);  // drive straight
  }
}
