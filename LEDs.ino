void setupLED()
{
  Serial.print("Adressable RGB LED Setup...");
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("  ...RGB LEDs ready for control");
}

void testLED()
{
  Serial.println("LED Test");
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++)
    {  // strip.Color takes RGB values, from 0,0,0 up to 255,255,255 in the order of GRB
       strip.setPixelColor(i, strip.Color(113,0,197)); // intel blue rgb(0, 113, 197)
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
    strip.setPixelColor(0, strip.Color(0,255,0));
    strip.setPixelColor(3, strip.Color(0,255,0));
    strip.show(); // This sends the updated pixel color to the hardware.
}

void driveLED()
{
  clearLED(); // Initialize all pixels to 'off'
    strip.setPixelColor(1, strip.Color(255,255,255));
    strip.setPixelColor(2, strip.Color(255,255,255));
    strip.show(); // This sends the updated pixel color to the hardware.  
}

void rightLED()
{
  for(int t=0; t<3; t++){
  clearLED(); // Initialize all pixels to 'off'
  delay(150);
    strip.setPixelColor(2, strip.Color(165,255,0));
    strip.setPixelColor(3, strip.Color(165,255,0));
    strip.show(); // This sends the updated pixel color to the hardware.  
    delay(250);
  }
}

void leftLED()
{
  for(int t=0; t<3; t++){
  clearLED(); // Initialize all pixels to 'off'
  delay(150);
    strip.setPixelColor(0, strip.Color(165,255,0));
    strip.setPixelColor(1, strip.Color(165,255,0));
    strip.show(); // This sends the updated pixel color to the hardware.    
  delay(250);
  }
}

void clearLED()
{
  for (int l=0; l<NUMPIXELS; l++)
    { strip.setPixelColor(l, strip.Color(0,0,0));  }
  strip.show();
}
