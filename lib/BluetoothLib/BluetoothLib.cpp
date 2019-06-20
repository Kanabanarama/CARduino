#include <Arduino.h>
#include <SoftwareSerial.h>

#include "BluetoothLib.h"

/**
 * @file BluetoothLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

BluetoothClass::BluetoothClass() {
  btSerial = new SoftwareSerial(rxPin,txPin);
  btSerial->begin(9600);
}

boolean BluetoothClass::isConnected() const {
  Serial.println(btSerial->available());
  return btSerial->available() > 0;
}

char * BluetoothClass::getValue() const {
  if(btSerial->available()){
    char commandbuffer[10];
    int i = 0;
    char params[0];

    while(btSerial->available() && i< 9) {
      commandbuffer[i++] = btSerial->read();
      params[i++] = btSerial->read();
    }
    commandbuffer[i++]='\0';
    params[i++]='\0';

    return commandbuffer;
  }

  return false;
}
