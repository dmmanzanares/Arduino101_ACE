#include "BLE_Main.h"

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
