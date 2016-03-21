/* Adapted from Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this 
  sketch!
  
  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed]) -- Drive [motor] 
      (0 for A, 1 for B) in [direction] (0 or 1) at a [speed]
      between 0 and 255. It will spin until told to stop.
    stopArdumoto([motor]) -- Stop driving [motor] (0 or 1).
  
  setupArdumoto() is called in the setup().
  The testArdumoto() demonstrates use of the motor driving functions.
*/

// setupArdumoto initialize all pins
void setupArdumoto()
{
  Serial.println("Setup Ardumoto Shield");
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
  Serial.println("  Motors ready for control");
}

void testArdumoto()
{
  Serial.println("Forward");
  forward(1000);
  stopMotors();
  delay(2000);
  Serial.println("Right");
  right(500);
  stopMotors();
  delay(2000);
  Serial.println("Left");
  left(500);
  stopMotors();
  delay(2000);
  Serial.println("Backward");
  backward(1000);
  stopMotors();
  delay(2000);  
}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

//Forwards full speed both motors on
void forward(int mdelay)
{
  // Now go forwards at half speed;
  driveArdumoto(MOTOR_A, CW, 127);  // Motor A at max speed.
  driveArdumoto(MOTOR_B, CW, 127);  // Motor B at max speed.
  delay(mdelay);
}

//Backwards half speed both motors on
void backward(int mdelay)
{
  // Now go backwards at half that speed:
  driveArdumoto(MOTOR_A, CCW, 127);  // Motor A at half speed.
  driveArdumoto(MOTOR_B, CCW, 127);  // Motor B at half speed.
  delay(mdelay);
}

//Right full and half speed Motor A
void right(int mdelay)
{
  // Drive motor A (and only motor A) at various speeds, then stop.
  //driveArdumoto(MOTOR_A, CW, 255); // Set motor A to CCW at max
  //delay(1000);  // Motor A will spin as set for 1 second
  driveArdumoto(MOTOR_A, CW, 127);  // Set motor A to CW at half
  delay(mdelay);  // Motor A will keep trucking for 1 second   
}

//Leftt full and half speed Motor B
void left(int mdelay)
{
  // Drive motor B (and only motor B) at various speeds, then stop.
  //driveArdumoto(MOTOR_B, CW, 255); // Set motor A to CCW at max
  //delay(1000);  // Motor A will spin as set for 1 second
  driveArdumoto(MOTOR_B, CW, 127);  // Set motor A to CW at half
  delay(mdelay);  // Motor A will keep trucking for 1 second   
}

//Stop both Motors A and B
void stopMotors()
{
  stopArdumoto(MOTOR_A);  // STOP motor A 
  stopArdumoto(MOTOR_B);  // STOP motor B 
}

