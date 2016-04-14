//#include "BLE_Main.h"
#include "CarDemo.h"

const int ctrlPin = 4;
BLEPeripheral bleCarRemote;
BLEService ioService("1815");

//
BLECharCharacteristic motorStateSwitchChrtc("2A56", BLERead | BLEWrite );

void CarDemo::setupBLE () {
  bleCarRemote.setLocalName("fnfCar");
  bleCarRemote.setAdvertisedServiceUuid(ioService.uuid());
  bleCarRemote.addAttribute(ioService);
  bleCarRemote.addAttribute(motorStateSwitchChrtc);
  motorStateSwitchChrtc.setValue(0);

    // assign event handlers for connected, disconnected to peripheral
  bleCarRemote.setEventHandler(BLEConnected, bleCarRemoteConnectHandler);
  bleCarRemote.setEventHandler(BLEDisconnected, bleCarRemoteDisconnectHandler);
  
  //callbacks for Switch Characteristic

  motorStateSwitchChrtc.setEventHandler(BLEWritten, motorStateSwitchChrtcWritten);
  
  bleCarRemote.begin();
}

void pollForConnect () {
  BLECentral central = bleCarRemote.central();
}

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
  // central wrote new value to characteristic, update LED
  Serial.print("Characteristic event, written: ");

//  if (motorStateSwitchChrtc.value()) {
//    Serial.println("Turning Motor On");
//    // code to start motor
//  } else {
//    Serial.println("Turning Motor off");
//    // code to stop motor
//  }
}



