#include <Arduino.h>
#include <SoftwareSerial.h>

#include "BluetoothLib.h"

/**
 * @file BluetoothLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.1
 */

static bool BluetoothClass::type = BluetoothClass::HARDWARE_SERIAL;
static bool BluetoothClass::connected = false;


BluetoothClass::BluetoothClass(int type = BluetoothClass::HARDWARE_SERIAL) {
  BluetoothClass::type = type;
}

SoftwareSerial *btSerial;

void BluetoothClass::start() const {
  if(type == BluetoothClass::HARDWARE_SERIAL) {
    Serial.begin(9600);
  } else {
    btSerial = new SoftwareSerial(rxPin,txPin);
    btSerial->begin(9600);
  }
  /*pinMode(statePin, INPUT);*/
}

unsigned long duration;

bool BluetoothClass::isConnected() const {
  // the state pin on my HC-06 module does nothing at all
  /*duration = pulseIn(statePin, HIGH);
  if(duration > 0) {
    return true;
  }*/

  return BluetoothClass::connected;
}

void BluetoothClass::sendValue(char * value) const {
  if(BluetoothClass::type == BluetoothClass::HARDWARE_SERIAL) {
    Serial.write(value);
  } else {
    btSerial->write(value);
  }
}

char buffer[42];
int charsRead;

char * BluetoothClass::getValue() const {
  buffer[0] = '\0';
  if(BluetoothClass::type == BluetoothClass::HARDWARE_SERIAL) {
    while(Serial.available() > 0) {
      BluetoothClass::connected = true;
      charsRead = Serial.readBytesUntil('\n', buffer, sizeof(buffer)-1);
      buffer[charsRead-1] = '\0';
    }
  } else {
    while(btSerial->available() > 0) {
      BluetoothClass::connected = true;
      charsRead = btSerial->readBytesUntil('\n', buffer, sizeof(buffer)-1);
      buffer[charsRead-1] = '\0';
    }
  }

  return buffer;
}
