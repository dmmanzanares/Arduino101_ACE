//#define ENABLE_SERVO
//#define ENABLE_PROXIMITY
//#define ENABLE_MOTORSHIELD
//#define ENABLE_BUZZER
//#define ENABLE_TAP
//#define ENABLE_ENCODER
#define ENABLE_LED

// Prototypes
void setupBuzzer();
void Buzzer();
void testBuzzer();

void setupCurie();

void setupEncoders();
void testEncoders();
void countA();
void countB();

void setupLED();
void testLED();
void brakeLED();
void driveLED();
void rightLED();
void leftLED();

void setupArdumoto();
void testArdumoto();
void driveArdumoto(byte motor, byte dir, byte spd);
void stopArdumoto(byte motor);
void forward(int mdelay);
void backward(int mdelay);
void right(int mdelay);
void left(int mdelay);
void stopMotors();

void setupProximity();
void testProximity();

void setupServo();
void testServo();
