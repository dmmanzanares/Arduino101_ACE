#include "CarDemo.h"
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
