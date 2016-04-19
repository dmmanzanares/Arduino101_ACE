/* LED Demo #2
 * This sketch turns on LEDs in a cyclical pattern 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object
long colors[13] = {RED, LIME, BLUE, YELLOW, CYAN, MAGENTA, SILVER, GRAY, MAROON, GREEN, PURPLE, TEAL, NAVY};

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.clearLED();  // turn all LEDs off
}

void loop() {
  for (int c=0; c < 13; c++) {     // loop through 13 pre-defined colors
    for (int i = 0; i < 4; i++) {  // loop theough all 4 car LEDs
      car.setLED(i, colors[c]);    // set LED (i) to new color
      delay(100);
      car.clearLED();              // turn all LEDs off
    }
  }
}
