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
	float distance = getRange();
	Serial.print("Dist = ");
    Serial.println(distance);
}

float CarDemo::getRange()
{
    float total = 0;
    int n;
    float max = 0.0;
    for (n = 0; n < 5; n++)
    {
      total = total + analogRead(PROXIMITY);
      if (n > max) {
          max = n;
      }
    }
    total = total - max;    // ignore highest value 
    float distance = total / (float) (n-1);  // take the average
    float volts = distance*0.0048828125;  // value from sensor * (5/1024)
    distance = 13*pow(volts, -1); // worked out from datasheet graph
	return distance;
}

bool CarDemo::checkObstacle(int minDist)
{
    float dist = getRange();
	//Serial.println(dist);
	//Serial.print("min = ");
	//Serial.println((float) minDist);
	return (dist < (float) minDist);
}
