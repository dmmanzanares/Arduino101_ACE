
#include <Adafruit_NeoPixel.h>

const byte NUMPIXELS = 4;  // number of RGB LEDs used

// Addressable RGB LED definitions...like a NeoPixel
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);
// IMPORTANT: To reduce LED burnout risk, add 0.1 uF capacitor across pixel power leads,
// add 50 - 100 Ohm resistor on first pixel's data input
// Avoid connecting on a live circuit...if you must, connect GND first.



void setupLED()
{
#ifdef ENABLE_LED
  Serial.print("Adressable RGB LED Setup...");
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("  ...RGB LEDs ready for control");
#else
  Serial.println("Led Disabled");
#endif
}

void testLED()
{
#ifndef ENABLE_LED
  Serial.println("LED Test, Skipped");
  return;
#endif
  Serial.println("LED Test");
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++)
  { // strip.Color takes RGB values, from 0,0,0 up to 255,255,255 in the order of GRB
    strip.setPixelColor(i, strip.Color(113, 0, 197)); // intel blue rgb(0, 113, 197)
  }
  strip.show(); // This sends the updated pixel color to the hardware.
  delay(1000); // Delay for a period of time (in milliseconds).
  clearLED();

  Serial.println("  STOP");
  brakeLED();
  delay(2000);
  Serial.println("  GO");
  driveLED();
  delay(2000);
  Serial.println("  Turning Right");
  rightLED();
  delay(800);
  Serial.println("  Turning Left");
  leftLED();
  delay(800);
}

void brakeLED()
{
  clearLED(); // Initialize all pixels to 'off'
  strip.setPixelColor(0, strip.Color(0, 255, 0));
  strip.setPixelColor(3, strip.Color(0, 255, 0));
  strip.show(); // This sends the updated pixel color to the hardware.
}

void driveLED()
{
  clearLED(); // Initialize all pixels to 'off'
  strip.setPixelColor(1, strip.Color(255, 255, 255));
  strip.setPixelColor(2, strip.Color(255, 255, 255));
  strip.show(); // This sends the updated pixel color to the hardware.
}

void rightLED()
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

void leftLED()
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

void clearLED()
{
  for (int l = 0; l < NUMPIXELS; l++)
  {
    strip.setPixelColor(l, strip.Color(0, 0, 0));
  }
  strip.show();
}
