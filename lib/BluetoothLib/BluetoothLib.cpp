#include <Arduino.h>
#include <SoftwareSerial.h>

#include "BluetoothLib.h"

/**
 * @file BluetoothLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

BluetoothClass::BluetoothClass() {
  Serial1.begin(9600);
}

boolean BluetoothClass::isConnected() const {
  return Serial1.available() > 0;
}

char * BluetoothClass::getValue() const {
  char bluetoothValue = 0;
  if(BluetoothClass::isConnected()) {
    bluetoothValue = Serial1.read();
  }

  return bluetoothValue;
}
