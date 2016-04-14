#include "CarDemo.h"

void CarDemo::setupProximity()
{
  //Serial.println("IR Proximity Sensor Setup...");
  pinMode (PROXIMITY, INPUT);
  /*PROXIMITY: the pin where your sensor is attached.
    25: the number of readings the library will make before calculating an average distance.
    93: the difference between two consecutive measurements to be taken as valid (in %)
    model: is an int that determines your sensor:  1080 for GP2Y0A21Y, 20150 for GP2Y0A02Y
    The numbers reflect the distance range they are designed for (in cm)*/
  //Our model is GP2Y0A41SK0F a range of 4 to 30cm so should be model 430
  //Serial.println("  ...IR Proximity Sensor ready for control");
}

void CarDemo::testProximity()
{

    Serial.println("IR Proximity Test");
    //  int dis=sharp.distance();  // this returns the distance to the object you're measuring
    int total = 0;
    int n;
    for (n = 0; n < 30; n++)
    {
      total = total + analogRead(PROXIMITY);
    }
    float distance = total / 30.0;
    //float volts = analogRead(total)*0.0048828125;   // value from sensor * (5/1024)
    //float distance = 27.728 * pow(map(total, 0, 1023, 0, 5000)/1000.0, -1.2045);
    //float distance = 65*pow(volts, -1.10);
    Serial.print("Dist = ");
    Serial.println(distance / n);

}
