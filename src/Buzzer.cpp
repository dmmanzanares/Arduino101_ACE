#include "CarDemo.h"
#include "pitches.h"
void CarDemo::setupBuzzer()
{
  // all pins as output
  pinMode(BUZZER, OUTPUT);
  // Initialize all pins as low:
  digitalWrite(BUZZER, LOW);
}

void CarDemo::testBuzzer()
{
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5)
  {
    // sets the value (range from 0 to 255):
    analogWrite(BUZZER, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5)
  {
    // sets the value (range from 0 to 255):
    analogWrite(BUZZER, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

void CarDemo::playCharge() {
	int charge[] = { NOTE_C4,NOTE_E4,NOTE_G4,NOTE_C5,NOTE_A5,NOTE_C5};
	int chargeDurations[] = {8,8,8,4,8,2};
	for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / chargeDurations[thisNote];
    tone(BUZZER, charge[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER);
  }
}	
