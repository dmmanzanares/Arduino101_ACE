void setupBuzzer()
{
Serial.print("Buzzer setup...");
// all pins as output
  pinMode(PWMBUZZER, OUTPUT);
// Initialize all pins as low:
  digitalWrite(PWMBUZZER, LOW);
Serial.println("  ...Buzzer ready for control");
}

void Buzzer()
{
  for (int n=0; n<3; n++) {
  analogWrite(PWMBUZZER, 127);
  delay (300);
  digitalWrite(PWMBUZZER, LOW);
  delay(300);
  }
}

void testBuzzer()
{ 
  Serial.println("Buzzer Test");
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) 
  { 
     // sets the value (range from 0 to 255):
    analogWrite(PWMBUZZER, fadeValue);   
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) 
  { 
    // sets the value (range from 0 to 255):
    analogWrite(PWMBUZZER, fadeValue);
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);  
  }
}
