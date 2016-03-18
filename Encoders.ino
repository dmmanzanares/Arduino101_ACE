//void count(void); // code for counting the increasing values of encoder ticks 

void setupEncoders()
{
pinMode(ENCA, INPUT);
pinMode(ENCB, INPUT);
attachInterrupt(ENCA, countA, FALLING);
attachInterrupt(ENCB, countB, FALLING);
encorderAValue=0;
encorderBValue=0;
}

void testEncoders()
{
Serial.print("Starting\n"); // to print encoder value on the screen 
Serial.print("Encoder A Value="); 
Serial.print(encorderAValue);
Serial.print("  |  Encoder B Value="); 
Serial.println(encorderBValue);
}

void countA()
{
encorderAValue++;
}
void countB()
{
encorderBValue++;
}
