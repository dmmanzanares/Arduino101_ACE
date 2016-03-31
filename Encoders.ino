
//void count(void); // code for counting the increasing values of encoder ticks

//Encoder definitions
int encorderAValue = 0;
int encorderBValue = 0;

void setupEncoders()
{
#ifdef ENABLE_ENCODERS
  Serial.print("Motor Encoder Setup...");
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(ENCA, countA, CHANGE);
  attachInterrupt(ENCB, countB, CHANGE);
  encorderAValue = 0;
  encorderBValue = 0;
  Serial.println("  ...Encoders capturing data and ready for control");
#else
  Serial.println("Encoder Disabled");
#endif
}

void testEncoders()
{
#ifndef ENABLE_ENCODERS
  Serial.println("Encoder Test, Skipped");
  return;
#endif
  Serial.print("Starting\n"); // to print encoder value on the screen
  Serial.print("Encoder A Value=");
  Serial.print(encorderAValue);
  Serial.print("  |  Encoder B Value=");
  Serial.println(encorderBValue);
}
/*
  void countA()
  {
  encorderAValue++;
  }
  void countB()
  {
  encorderBValue++;
  }
*/
//const byte ENCA = 2;
// const byte ENCB = 8;

int motorTime = 120;                     // width of pulse in mS we want the motor to run (120 is pretty slow)

volatile unsigned long lpulse = 121;      // width of left encoder pulses in mS

volatile unsigned long rpulse = 121;      // width of right encoder pulses in mS
volatile unsigned long ltime;             // remembers time of left  encoders last state change in mS
volatile unsigned long rtime;             // remembers time of right encoders last state change in m

//#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))

void enCoderSetup()
{
  // enable pullup resistors
  digitalWrite(ENCA, 1);
  digitalWrite(ENCB, 1);

  attachInterrupt(ENCA, Lencoder, CHANGE);                     // trigger left  encoder ISR on state change
  attachInterrupt(ENCB, Rencoder, CHANGE);                     // trigger right encoder ISR on state change
}

//======================================================= ISR for left encoder =======================================================
void Lencoder()
{
  lpulse=millis()-ltime;                               // time between last state change and this state change
  ltime=millis();  // update ltime with time of most recent state change
}

//======================================================= ISR for right encoder ======================================================
void Rencoder()
{
  rpulse=millis()-rtime;                               // time between last state change and this state change
  rtime=millis();  // update ltime with time of most recent state change
}

void encoderloop() {
//  runEvery(500)
//#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))  
//  for (int _lasttime = 500; (millis() - lasttime) >
//  {
//    Serial.print("lpulse = ");
//    Serial.println(lpulse);
//    Serial.print("rpulse = ");
//    Serial.println(rpulse);
//    Serial.print("speedLeft = ");
//    Serial.println(speedLeft);
//    Serial.print("speedRight = ");
//    Serial.println(speedRight);
//  }
//  runEvery(5){                            // Run every 5ms, to fast would stop the motors
//    int lastPulseL = millis() - ltime;     // Check how much time has passed since last pulse
//    int lastPulseR = millis() - rtime;
//    if (lastPulseL > motorTime && speedLeft < 255)    // If the pulse is longer then the time we want speed up motor
//    {
//      speedLeft = speedLeft+1;
//    }
//    if (lastPulseL < motorTime && speedLeft > 0)      // // If the pulse is shorter then the time we want slow down motor
//    {
//     speedLeft = speedLeft-1;
//    }
//    if (lastPulseR > motorTime && speedRight < 255)
//    {
//      speedRight = speedRight+1;
//    }
//    if (lastPulseR < motorTime && speedRight > 0)
//    {
//      speedRight = speedRight-1;
//    }
//  }
//  forward();

  //backward();
  //left();
  //right();
}

//void forward()
//{
//  digitalWrite(direction1, HIGH);
//  digitalWrite(direction2, HIGH); 
//  analogWrite(EN1, speedLeft);
//  analogWrite(EN2, speedRight);
//}
//
//void stop()
//{
//  digitalWrite(direction1, LOW); 
//  digitalWrite(direction2, LOW); 
//  analogWrite(EN1, 0);
//  analogWrite(EN2, 0);
//}
//
//void backward()
//{
//  digitalWrite(direction1, LOW);
//  digitalWrite(direction2, LOW); 
//  analogWrite(EN1, speedLeft);
//  analogWrite(EN2, speedRight);
//}
//
//void left()
//{
//  digitalWrite(direction1, LOW);
//  digitalWrite(direction2, HIGH); 
//  analogWrite(EN1, speedLeft);
//  analogWrite(EN2, speedRight);
//}
//
//void right()
//{
//  digitalWrite(direction1, HIGH);
//  digitalWrite(direction2, LOW); 
//  analogWrite(EN1, speedLeft);
//  analogWrite(EN2, speedRight);
//}