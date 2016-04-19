/* Buzzer Demo
 * This sketch tests the piezo buzzer 
 */
#include <CarDemo.h>
#include "pitches.h"

CarDemo car;  // Create CarDemo library object

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors
  
  // Define a little song with pre-defined notes
  // To calculate the note duration, take one second
  // divided by the note type.
  //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  int Notes[] = { NOTE_C4,NOTE_E4,NOTE_G4,NOTE_C5,NOTE_A5,NOTE_C5};
  int Durations[] = {8,8,8,4,8,2};  // song-note durations
  int Length = 6;                   // number of notes in song
  
  car.playSong(Notes, Durations, Length);  // play the song
  // delay(1000);
  // car.playNote(NOTE_C4, 1); // play note C_4 for 1-second
}

void loop() {
  // put your main code here, to run repeatedly:

}