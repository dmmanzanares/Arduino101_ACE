/*
    This is dereived from the testMotor
    Download Nordic Master Controller from Google Play or Blue Light for IOS
    Scan for devices and connect to fnfCar device
    Look for the Control Serivce and then look for the Digital Charcteristic
    Write a Byte Value to it According to the following command table
 *   ***** Command Codes  *****
      Write to the Control Characteritic on the Digital Value
      0x40 = Turn Motor Forward for 1 second
      0x3F  = Turn Motor
      0x11 = Stop Motor
      0x4F = Turn Motor longer
      0x3F = Turn Car Right
      0x2F = Turn Car Left
      0x20 = Turn Motor Backwards
     You can add additional codes and call other commands for LED buzzer etc
     Add in the callback function motorStateSwitchChrtcWritten(
     TODO Add Notification Characteristic to tell speed in the loop
     This is for testing if you need to run without serial monitor have to remove all serial print commands in callbacks
     Author Noel Paz
*/


#include "CarDemo.h"
#include <CurieBLE.h>



// Callback prototypes
void bleCarRemoteConnectHandler(BLECentral & central);
void bleCarRemoteDisconnectHandler(BLECentral & central);
void motorStateSwitchChrtcWritten(BLECentral& central, BLECharacteristic & characteristic);

//const int ctrlPin = 4;
BLEPeripheral bleCarRemote;
BLEService ioService("1815");
BLECharCharacteristic motorStateSwitchChrtc("2A56", BLERead | BLEWrite );
CarDemo car;  // Create CarDemo library object
int speed = FULLSPEED;  // speed setting (maximum is 255)

void setup() {
  while (!Serial) {

  }
  Serial.begin(115200);

  bleCarRemote.setLocalName("fnfCar");  //this is what the BLE app will connect too
  bleCarRemote.setAdvertisedServiceUuid(ioService.uuid());
  bleCarRemote.addAttribute(ioService); //You will see this as Control service -- name is standard
  bleCarRemote.addAttribute(motorStateSwitchChrtc);  // this is the BLE data charcteristic that we will update in the client
  motorStateSwitchChrtc.setValue(0);

  // assign event handlers for connected, disconnected to peripheral
  bleCarRemote.setEventHandler(BLEConnected, bleCarRemoteConnectHandler);  //tells we connected to a BLE app or master
  bleCarRemote.setEventHandler(BLEDisconnected, bleCarRemoteDisconnectHandler);  //tells we connected

  //callbacks for Switch Characteristic
  motorStateSwitchChrtc.setEventHandler(BLEWritten, motorStateSwitchChrtcWritten);  //main call back that reacts to waht we right to the Digital characteristic in the app
  //Serial.println("Waiting..");
  bleCarRemote.begin();  //start BLE first before car setuo
  car.setupCar();  // setup all sensors and motors
  car.clearLED(); // turn all LEDs off

}

void loop() {
  // we can add a BLE notification chatcteristic to poll for encoder data
  BLECentral central = bleCarRemote.central();  // waits for a connection
}
// The next two callbacks are just to make us aware we connected
void bleCarRemoteConnectHandler(BLECentral & central) {
  // central connected event handler
  Serial.print("Connected event, central: ");
  Serial.println(central.address());

}

void bleCarRemoteDisconnectHandler(BLECentral & central) {
  // central disconnected event handler
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
}

void motorStateSwitchChrtcWritten(BLECentral& central, BLECharacteristic & characteristic) {
  // BLE app wrote to our service here we have code that interprets those values
  // If they are not valid we don't call anything but we print them
  Serial.println("Characteristic event, Command written: ");
  Serial.println(motorStateSwitchChrtc.value(), HEX);

  /***** Command Codes  ***** /
      Write to the Control Characteritic on the Digital Value
      0x40 = Turn Motor Forward for 1 second
      0x3F  = Turn Motor
      0x11 = Stop Motor
      0x4F = Turn Motor longer
      0x3F = Turn Car Right
      0x2F = Turn Car Left
      0x20 = Turn Motor Backwards
  */

  //Move forward
  if ( motorStateSwitchChrtc.value() == 0x40 ) {
    Serial.println("Motor Start Command");
    car.motorsWrite(speed, speed);  // both motors forward
    delay(1000);
    car.stopMotors(); // stop both motors
  }
  // right
  if ( motorStateSwitchChrtc.value() == 0x3F ) {
    Serial.println("Motor Right Command");
    car.motorsWrite(speed, -1 * speed); // left forward, right backward (negative)
    delay(1000);
    car.stopMotors(); // stop both motors
  }
  // left
  if ( motorStateSwitchChrtc.value() == 0x2F ) {
    Serial.println("Motor Left Command");
    car.motorsWrite(-1 * speed, speed); // left backward (negative), right forward
    delay(1000);
    car.stopMotors(); // stop both motors

  }
  //Backward
  if ( motorStateSwitchChrtc.value() == 0x30 ) {
    Serial.println("Motor Backward Command");
    car.motorsWrite(-1 * speed, -1 * speed); // both motors backward (negative)
    delay(1000);
    car.stopMotors(); // stop both motors
  }

  //   Stop Motor Kill switch
  //Currently not working need to Ask Brian how to stop
  if ( motorStateSwitchChrtc.value() == 0x11 ) {
    Serial.println("Motor STOP Command");

    car.stopMotors(); // stop both motors
  }
  // forward longer to demonstrate stop
  if ( motorStateSwitchChrtc.value() == 0x4F ) {
    Serial.println("Motor Run Longer Command");
    car.motorsWrite(speed, speed);  // both motors forward
    delay(20000);
    car.stopMotors(); // stop both motors
  }



}
