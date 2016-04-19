/* Proximity Sensor Demo
 * This sketch tests the Proximity Sensor. Turns LEDs red/yellow if object is
 * detected nearby
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.clearLED(); // turn all LEDs off
}

void loop() {
  float dist = car.getRange();    // get proximity sensor range reading (in inches)
  Serial.println(dist);
  if (dist < 10.0) {
    car.setLED(ALL_LEDS, RED);    // set LEDs red for near object (< 10")
  } else if (dist < 15.0) {
    car.setLED(ALL_LEDS, YELLOW); // set LEDs yellow for nearby object (< 15")
  } else {
    car.setLED(ALL_LEDS, GREEN);  // set LEDs green for far object
  }
  delay(50);
}
