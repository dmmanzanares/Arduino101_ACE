void setupLED()
{
  pixels.begin(); // This initializes the NeoPixel library.
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void testLED()
{
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++)
    {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
      // intel blue rgb(0, 113, 197)
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(500); // Delay for a period of time (in milliseconds).
    }
}

void brakeLED()
{
  strip.show(); // Initialize all pixels to 'off'
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.setPixelColor(1, pixels.Color(255,0,0));
    pixels.show(); // This sends the updated pixel color to the hardware.
}

void driveLED()
{
  strip.show(); // Initialize all pixels to 'off'
    pixels.setPixelColor(2, pixels.Color(255,255,255));
    pixels.setPixelColor(3, pixels.Color(255,255,255));
    pixels.show(); // This sends the updated pixel color to the hardware.  
}

void rightLED()
{
  strip.show(); // Initialize all pixels to 'off'
    pixels.setPixelColor(0, pixels.Color(255,255,0));
    pixels.setPixelColor(3, pixels.Color(255,255,0));
    pixels.show(); // This sends the updated pixel color to the hardware.  
}

void leftLED()
{
  strip.show(); // Initialize all pixels to 'off'
    pixels.setPixelColor(1, pixels.Color(255,255,0));
    pixels.setPixelColor(2, pixels.Color(255,255,0));
    pixels.show(); // This sends the updated pixel color to the hardware.    
}

