#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object
long colors[13] = {RED, LIME, BLUE, YELLOW, CYAN, MAGENTA, SILVER, GRAY, MAROON, GREEN, PURPLE, TEAL, NAVY};


void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  car.clearLED(); // turn all LEDs off

}

void loop() {
  for (int c=0; c < 13; c++) {
    for (int i = 0; i < 4; i++) {
      car.setLED(i, colors[c]);
      delay(100);
      car.clearLED();
    }
  }
}
