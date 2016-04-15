/* LED Demo
 * This sketch tests all the LED light sequences 
 */
#include <CarDemo.h>

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  
  Serial.println("LED Test");
  car.clearLED(); // turn all LEDs off
  delay(1000);
  Serial.println("  STOP");
  car.brakeLED(); // turn on brake LEDs
  delay(2000);
  Serial.println("  GO");
  car.driveLED(); // turn on headlight LEDs
  delay(2000);
  Serial.println("  Turning Right");
  car.rightLED(); // turn on right turn signals
  delay(2000);
  Serial.println("  Turning Left");
  car.leftLED(); // turn on left turn signals
  delay(2000);
  Serial.println("  PAUSED");
  car.pauseLED(); // turn on pause lights
  delay(1000);
  Serial.println("  STARTING");
  car.startingLED(); // turn on start-up lights
  delay(1000);
  car.clearLED();  // turn all LEDs off
}

void loop() {
  // put your main code here, to run repeatedly:

}
