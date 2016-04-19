/* Intermediate Car Demo
 * This sketch plays piezo buzzer , spins around and flashes LEDs
 */
 #include <CarDemo.h>
 #include "pitches.h"   // pre-defined list of notes

CarDemo car;

// Song data for the piezo buzzer
int Notes[] = { NOTE_C4,NOTE_E4,NOTE_G4,NOTE_C5,NOTE_A5,NOTE_C5};
int Durations[] = {8,8,8,4,8,2};  // song-note durations
int Length = 6;                   // number of notes in song

void setup() {
  Serial.begin(115200);
  car.setupCar();    // setup car and pause. (tilt car to continue)
  delay(2000);
  car.playSong(Notes, Durations, Length);  // play the song
}

int carspeed = 255;  // full-speed speed (100% PWM duty cycle)

void loop() {
  car.motorsWrite(carspeed, -1*carspeed); // spin in one direction
  car.setLED(ALL_LEDS, RED);     // turn all LEDS red
  delay(500);
  car.setLED(ALL_LEDS, BLUE);    // turn all LEDs blue
  delay(500);
  car.setLED(ALL_LEDS, WHITE);   // turn all LEDs white
  delay(500);
  carspeed = carspeed * -1;   // reverse spin direction
}
