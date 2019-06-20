#ifndef _CARDUINO_BLUETOOTH_LIB_
#define _CARDUINO_BLUETOOTH_LIB_

/**
 * @file BluetoothLib.h
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothClass {

	public:

		BluetoothClass();

    bool isConnected() const;
		char* getValue() const;

	private:

		const int rxPin = 12;
		const int txPin = 11;
		SoftwareSerial *btSerial;

};

#endif
