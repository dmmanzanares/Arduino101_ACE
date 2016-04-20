#include "CarDemo.h"
#include <Arduino.h>

int encoderLValue;
int encoderRValue;
int encoderLStopCount;
int encoderRStopCount;

void CarDemo::setupEncoders()
{
  pinMode(ENCL, INPUT_PULLUP);
  pinMode(ENCR, INPUT_PULLUP);
  attachInterrupt(ENCL, countL, FALLING);
  attachInterrupt(ENCR, countR, FALLING);
  encoderLValue = 0;
  encoderRValue = 0;
  encoderLStopCount = 0;
  encoderRStopCount = 0;
}

void countL()
{
  encoderLValue++;
}
void countR()
{
  encoderRValue++;
}
