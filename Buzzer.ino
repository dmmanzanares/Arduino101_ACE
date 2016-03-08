void setuphorn()
{
  // all pins as output
   pinMode(PWMHORN, OUTPUT);
// Initialize all pins as low:
  digitalWrite(PWMHORN, LOW);
}

void horn()
{
  for (int n=0; n<3; n++) {
  analogWrite(PWMHORN, 127);
  delay (300);
  digitalWrite(PWMHORN, LOW);
  delay(300);
  }
}

void testhorn()
{ 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) 
  { 
     // sets the value (range from 0 to 255):
    analogWrite(PWMHORN, fadeValue);   
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) 
  { 
    // sets the value (range from 0 to 255):
    analogWrite(PWMHORN, fadeValue);
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);  
  }
}
