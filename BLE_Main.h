#include <BLEAttribute.h>
#include <BLECentral.h>
#include <BLECharacteristic.h>
#include <BLECommon.h>
#include <BLEDescriptor.h>
#include <BLEPeripheral.h>
#include <BLEService.h>
#include <BLETypedCharacteristic.h>
#include <BLETypedCharacteristics.h>
#include <BLEUuid.h>
#include <CurieBLE.h>

// Callback prototypes
void bleCarRemoteConnectHandler(BLECentral & central);
void bleCarRemoteDisconnectHandler(BLECentral & central);
void motorStateSwitchChrtcWritten(BLECentral& central, BLECharacteristic & characteristic);

