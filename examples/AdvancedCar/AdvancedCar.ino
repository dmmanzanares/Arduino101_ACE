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
  //car.motorLSkew = 0.95; // slow up the left wheel to skew right (95% of right speed)
  //car.motorRSkew =;      // adjust for motor drift. 100% = straight
  car.clearLED();        // turn all LEDs off
  car.setServo(90);
}

void loop() {
  int carspeed = HALFSPEED;     // 127/255 PWM speed (50% duty cycle) 
  if (car.checkObstacle(14)) {  // check for close obstacle
    car.setLED(ALL_LEDS, RED);  // turn LEDs red if path is blocked
    car.stopMotors();           // stop motors
    moveLR(500);                   // scan surroundings and turn to best path
    car.stopMotors();           // stop motors
  } else if (car.checkObstacle(18)) {  // check for far obstacle
    car.setLED(ALL_LEDS, YELLOW);  // turn LEDs yellow if wall is detected
    car.stopMotors();           // stop motors
    moveLR(200);                // scan surroundings and turn to best path
    car.stopMotors();           // stop motors
  } else {
    car.setLED(ALL_LEDS, GREEN);          // if path is clear turn LEDs green
    car.motorsWrite(carspeed, carspeed);  // drive straight
  }
}
