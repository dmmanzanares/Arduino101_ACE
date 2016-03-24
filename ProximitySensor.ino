#include <Servo.h>
extern Servo myservo;

void setupProximity()
{
#ifdef ENABLE_PROXIMITY
  Serial.println("IR Proximity Sensor Setup...");
  pinMode (PROXIMITY, INPUT);
  /*PROXIMITY: the pin where your sensor is attached.
    25: the number of readings the library will make before calculating an average distance.
    93: the difference between two consecutive measurements to be taken as valid (in %)
    model: is an int that determines your sensor:  1080 for GP2Y0A21Y, 20150 for GP2Y0A02Y
    The numbers reflect the distance range they are designed for (in cm)*/
  //Our model is GP2Y0A41SK0F a range of 4 to 30cm so should be model 430
  Serial.println("  ...IR Proximity Sensor ready for control");
#else
  Serial.println("Proximity Disabled");
#endif
}

void testProximity()
{
#ifndef ENABLE_PROXIMITY
  Serial.println("IR Proximity, Skipped");
  return;
#endif

  Serial.println("IR Proximity Test");
  for (int d = 0; d < 3; d++)
  {
    //  int dis=sharp.distance();  // this returns the distance to the object you're measuring
    int total = 0;
    int n;
    if (d == 0) {
      myservo.write(0);  // look left
      Serial.print("  Mean distance (to Racer's Left): ");
    }
    else if (d == 1)  {
      myservo.write(180);  //look right
      Serial.print("  Mean distance (to Racer's Right): ");
    }
    else if (d == 2) {
      myservo.write(90);  // straigh ahead
      Serial.print("  Mean distance (Straigh ahead of Racer): ");  // returns it to the serial monitor
    }
    for (n = 0; n < 30; n++)
    {
      total = total + analogRead(PROXIMITY);
    }
    Serial.println(total / n);
  }
}
