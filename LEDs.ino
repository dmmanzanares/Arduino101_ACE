
void setupLED()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void testLED()
{
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++)
    {
    // strip.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0,150,0)); // Moderately bright green color.
      // intel blue rgb(0, 113, 197)
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(500); // Delay for a period of time (in milliseconds).
    }
}

void brakeLED()
{
  strip.show(); // Initialize all pixels to 'off'
    strip.setPixelColor(0, strip.Color(255,0,0));
    strip.setPixelColor(1, strip.Color(255,0,0));
    strip.show(); // This sends the updated pixel color to the hardware.
}

void driveLED()
{
  strip.show(); // Initialize all pixels to 'off'
    strip.setPixelColor(2, strip.Color(255,255,255));
    strip.setPixelColor(3, strip.Color(255,255,255));
    strip.show(); // This sends the updated pixel color to the hardware.  
}

void rightLED()
{
  strip.show(); // Initialize all pixels to 'off'
    strip.setPixelColor(0, strip.Color(255,255,0));
    strip.setPixelColor(3, strip.Color(255,255,0));
    strip.show(); // This sends the updated pixel color to the hardware.  
}

void leftLED()
{
  strip.show(); // Initialize all pixels to 'off'
    strip.setPixelColor(1, strip.Color(255,255,0));
    strip.setPixelColor(2, strip.Color(255,255,0));
    strip.show(); // This sends the updated pixel color to the hardware.    
}

