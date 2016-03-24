//#include "BLE_Main.h"


const int ctrlPin = 4;
BLEPeripheral bleCarRemote;
BLEService ioService("1815");

//
BLECharCharacteristic motorStateSwitchChrtc("2A56", BLERead | BLEWrite );

void setupBle () {
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



