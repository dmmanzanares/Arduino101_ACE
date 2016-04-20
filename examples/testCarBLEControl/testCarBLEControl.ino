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


#include <CurieBLE.h>
#include "CarDemo.h"

BLEPeripheral blePeripheral; // create peripheral instance

BLEService ioService("1815");

// create switch characteristic and allow remote device to read and write
BLECharCharacteristic switchChar("2A56", BLERead | BLEWrite);

CarDemo car;  // Create CarDemo library object
int speed = HALFSPEED;  // speed setting (50% duty cycle)

void setup() {
  Serial.begin(115200);
  car.setupCar();  // setup all sensors and motors

  // set the local name peripheral advertises
  blePeripheral.setLocalName("fnfCar");
  // set the UUID for the service this peripheral advertises
  blePeripheral.setAdvertisedServiceUuid(ioService.uuid());

  // add service and characteristic
  blePeripheral.addAttribute(ioService);
  blePeripheral.addAttribute(switchChar);

  // assign event handlers for connected, disconnected to peripheral
  blePeripheral.setEventHandler(BLEConnected, blePeripheralConnectHandler);
  blePeripheral.setEventHandler(BLEDisconnected, blePeripheralDisconnectHandler);

  // assign event handlers for characteristic
  switchChar.setEventHandler(BLEWritten, switchCharacteristicWritten);
// set an initial value for the characteristic
  switchChar.setValue(0);

  // advertise the service
  blePeripheral.begin();
  Serial.println(("Bluetooth device active, waiting for connections..."));
}

void loop() {
  // poll peripheral
  blePeripheral.poll();
}

void blePeripheralConnectHandler(BLECentral& central) {
  // central connected event handler
  Serial.print("Connected event, central: ");
  Serial.println(central.address());
}

void blePeripheralDisconnectHandler(BLECentral& central) {
  // central disconnected event handler
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
}

void switchCharacteristicWritten(BLECentral& central, BLECharacteristic& characteristic) {
  // central wrote new value to characteristic, update LED
  Serial.print("Characteristic event, written: ");
  // BLE app wrote to our service here we have code that interprets those values
  // If they are not valid we don't call anything but we print them
  Serial.println("Characteristic event, Command written: ");
  Serial.println(switchChar.value(), HEX);

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
  if ( switchChar.value() == 0x40 ) {
    Serial.println("Motor Start Command");
    car.motorsWrite(speed, speed);  // both motors forward
    delay(1000);
    car.stopMotors(); // stop both motors
  }
  // right
  if ( switchChar.value() == 0x3F ) {
    Serial.println("Motor Right Command");
    car.motorsWrite(speed, -1 * speed); // left forward, right backward (negative)
    delay(1000);
    car.stopMotors(); // stop both motors
  }
  // left
  if ( switchChar.value() == 0x2F ) {
    Serial.println("Motor Left Command");
    car.motorsWrite(-1 * speed, speed); // left backward (negative), right forward
    delay(1000);
    car.stopMotors(); // stop both motors

  }
  //Backward
  if ( switchChar.value() == 0x30 ) {
    Serial.println("Motor Backward Command");
    car.motorsWrite(-1 * speed, -1 * speed); // both motors backward (negative)
    delay(1000);
    car.stopMotors(); // stop both motors
  }

  //   Stop Motor Kill switch
  //Currently not working need to Ask Brian how to stop
  if ( switchChar.value() == 0x11 ) {
    Serial.println("Motor STOP Command");

    car.stopMotors(); // stop both motors
  }
  // forward longer to demonstrate stop
  if ( switchChar.value() == 0x4F ) {
    Serial.println("Motor Run Longer Command");
    car.motorsWrite(speed, speed);  // both motors forward
    delay(20000);
    car.stopMotors(); // stop both motors
  }
}
