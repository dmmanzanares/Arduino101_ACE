#include "CurieIMU.h"
#include "CarDemo.h"
/*
   This sketch example demonstrates how the BMI160 accelerometer on the
   Intel(R) Curie(TM) module can be used to detect tap events
*/

const int TILT_VALUE = 8000; // Max Z-accelleration when tilted

void CarDemo::setupMotion() {
  // Initialise the IMU
  CurieIMU.begin();

  delay(1000); // wait for sensor data to settle
}

bool CarDemo::tilted() {
  int z = CurieIMU.readAccelerometer(Z_AXIS);
  return (z < TILT_VALUE);
}
