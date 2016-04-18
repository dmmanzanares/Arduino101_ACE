/* Proximity Sensor Demo
 * This sketch tests the Proximity Sensor 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  
  car.clearLED(); // turn all LEDs off
}

void loop() {
  // put your main code here, to run repeatedly:
  float dist = car.getRange();
  Serial.println(dist);
  if (dist < 5.0) {
    car.setLED(ALL_LEDS, RED);
  } else if (dist < 10) {
    car.setLED(ALL_LEDS, YELLOW);
  } else {
    car.setLED(ALL_LEDS, GREEN);
  }
  delay(50);
}
