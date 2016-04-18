#include <Adafruit_NeoPixel.h>
#include "CarDemo.h"

//namespace CarDemo {

const byte NUMPIXELS = 4;  // number of RGB LEDs used

// Addressable RGB LED definitions...like a NeoPixel
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
// IMPORTANT: To reduce LED burnout risk, add 0.1 uF capacitor across pixel power leads,
// add 50 - 100 Ohm resistor on first pixel's data input
// Avoid connecting on a live circuit...if you must, connect GND first.

void CarDemo::setupLED()
{
  //Serial.print("Adressable RGB LED Setup...");
  strip = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //Serial.println("  ...RGB LEDs ready for control");
}

void CarDemo::clearLED()
{
  for (int l = 0; l < NUMPIXELS; l++)
  {
    strip.setPixelColor(l, strip.Color(0, 0, 0));
  }
  strip.show();
}

void CarDemo::pauseLED()
{
  clearLED();
  for (int l = 0; l < NUMPIXELS; l++)
  {
    strip.setPixelColor(l, strip.Color(0, 0, 255));
  }
  strip.show();
}

void CarDemo::brakeLED()
{
  clearLED(); // Initialize all pixels to 'off'
  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.setPixelColor(3, strip.Color(0, 255, 0));
  strip.show(); // This sends the updated pixel color to the hardware.
}

void CarDemo::driveLED()
{
  clearLED(); // Initialize all pixels to 'off'
  strip.setPixelColor(1, strip.Color(255, 255, 255));
  strip.setPixelColor(2, strip.Color(255, 255, 255));
  strip.show(); // This sends the updated pixel color to the hardware.
}

void CarDemo::rightLED()
{
  for (int t = 0; t < 3; t++) {
    clearLED(); // Initialize all pixels to 'off'
    delay(150);
    strip.setPixelColor(2, strip.Color(165, 255, 0));
    strip.setPixelColor(3, strip.Color(165, 255, 0));
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(250);
  }
}

void CarDemo::leftLED()
{
  for (int t = 0; t < 3; t++) {
    clearLED(); // Initialize all pixels to 'off'
    delay(150);
    strip.setPixelColor(0, strip.Color(165, 255, 0));
    strip.setPixelColor(1, strip.Color(165, 255, 0));
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(250);
  }
}

void CarDemo::startingLED()
{
  for (int t = 0; t < 8; t++) {
    clearLED(); // Initialize all pixels to 'off'
    delay(250);
    for (int l = 0; l < NUMPIXELS; l++)
    {
      strip.setPixelColor(l, strip.Color(255, 0, 0));
    }
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(250);
  }
}

void CarDemo::setLED(int led, long color)
{
  if (led == ALL_LEDS) {
	  for (int l = 0; l < NUMPIXELS; l++)
	  {
		strip.setPixelColor(l, color);
	  }
	  strip.show();
  } else {
	  strip.setPixelColor(led, color);
	  strip.show();
  }
}

void CarDemo::testLED()
{
  Serial.println("LED Test");
  clearLED();
  delay(1000);
  Serial.println("  STOP");
  brakeLED();
  delay(2000);
  Serial.println("  GO");
  driveLED();
  delay(2000);
  Serial.println("  Turning Right");
  rightLED();
  delay(2000);
  Serial.println("  Turning Left");
  leftLED();
  delay(2000);
  clearLED();
}
//} // namespace