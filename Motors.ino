
/* Adapted from Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this sketch!

  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed], [mdelay]) --
      Drive [motor] (0 for A, 1 for B, 2 for both) in [direction] (0 or 1) at a [speed] between 0 and 255, for length of time [mdelay].
    stopArdumoto([motor]) -- Stop driving both motors
      For ease of coding the functions have been created: forward, backward, right and left.  Each require speed and duration.
      To reduce the surge current on the battery...a fadein function has been created, to fade in from 0 to speed requested.
  setupArdumoto() is called in the setup().
  The testArdumoto() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
const byte CW  = 0;
const byte CCW = 1;

// Motor definitions to make life easier:
const byte MOTOR_A = 0;
const byte MOTOR_B = 1;
const byte MOTORS  = 2;


// setupArdumoto initialize all pins
void setupArdumoto()
{
#ifdef ENABLE_MOTORSHIELD
  Serial.print("Setup Ardumoto Shield...");
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
  Serial.println("  ...Motors ready for control");
#else
  Serial.println("Motor Disabled");
#endif
}

void testArdumoto()
{
#ifndef ENABLE_MOTORSHIELD
  Serial.println("Motor Test, Skipped");
  return;
#endif
  Serial.println("Motor Test");
  Serial.println("  Forward");
  forward(255, 1000);
  stopArdumoto();
  delay(2000);
  Serial.println("  Right");
  right(127, 500);
  stopArdumoto();
  delay(2000);
  Serial.println("  Left");
  left(127, 500);
  stopArdumoto();
  delay(2000);
  Serial.println("  Backward");
  backward(127, 1000);
  stopArdumoto();
  delay(2000);
}

// stopArdumoto makes a motor stop
void stopArdumoto()
{
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd, int mdelay)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
  }
  else if (motor == MOTORS)
  {
    digitalWrite(DIRA, dir);
    digitalWrite(DIRB, dir);
  }
  fadein(motor, spd);
  delay(mdelay); //run motors for this long
}

void fadein(byte motor, byte spd)
{
  // fade in from min to desired spd in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= spd; fadeValue += 5)
  {
    // sets the value (range from 0 to 255):
    if (motor == MOTOR_A)
    {
      analogWrite(PWMA, fadeValue);
    }
    else if (motor == MOTOR_B)
    {
      analogWrite(PWMB, fadeValue);
    }
    else if (motor == MOTORS)
    {
      analogWrite(PWMA, fadeValue);
      analogWrite(PWMB, fadeValue);
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
void forward(byte spd, int mdelay)
{
  // Drive motor A  and B at various speeds, for a specified length of time
  driveArdumoto(MOTORS, CW, spd, mdelay);  // Set motor A and B to CW at spd for mdelay time
}

void backward(byte spd, int mdelay)
{
  // Drive motor A  and B at various speeds, for a specified length of time
  driveArdumoto(MOTORS, CCW, spd, mdelay);  // Set motor A and B to CCW at spd for mdelay time
}
void right(byte spd, int mdelay)
{
  // Drive motor A  at various speeds, for a specified length of time
  driveArdumoto(MOTOR_A, CW, spd, mdelay);  // Set motor A to CW at spd for mdelay time
}

void left(byte spd, int mdelay)
{
  // Drive motor B at various speeds, for a specified length of time
  driveArdumoto(MOTOR_B, CW, spd, mdelay);  // Set motor B to CW at spd for mdelay time
}
