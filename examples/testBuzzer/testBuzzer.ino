/* Buzzer Demo
 * This sketch tests the piezo buzzer 
 */
#include <CarDemo.h>
#include "pitches.h"

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  
  int charge[] = { NOTE_C4,NOTE_E4,NOTE_G4,NOTE_C5,NOTE_A5,NOTE_C5};
  int chargeDurations[] = {8,8,8,4,8,2};
  
  car.playSong(charge, chargeDurations);
}

void loop() {
  // put your main code here, to run repeatedly:

}
