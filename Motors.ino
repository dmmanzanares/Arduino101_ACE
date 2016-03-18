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
}

void testArdumoto()
{
  forward(250);
  stopMotors();
  right();
  stopMotors();
  left();
  stopMotors();
  backward(250);
  stopMotors();
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
  // Now go forwards at full speed;
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
void right()
{
  // Drive motor A (and only motor A) at various speeds, then stop.
  //driveArdumoto(MOTOR_A, CW, 255); // Set motor A to CCW at max
  //delay(1000);  // Motor A will spin as set for 1 second
  driveArdumoto(MOTOR_A, CW, 127);  // Set motor A to CW at half
  delay(1000);  // Motor A will keep trucking for 1 second   
}

//Leftt full and half speed Motor B
void left()
{
  // Drive motor B (and only motor B) at various speeds, then stop.
  //driveArdumoto(MOTOR_B, CW, 255); // Set motor A to CCW at max
  //delay(1000);  // Motor A will spin as set for 1 second
  driveArdumoto(MOTOR_B, CW, 127);  // Set motor A to CW at half
  delay(1000);  // Motor A will keep trucking for 1 second   
}

//Stop both Motors A and B
void stopMotors()
{
  stopArdumoto(MOTOR_A);  // STOP motor A 
  stopArdumoto(MOTOR_B);  // STOP motor B 
}

