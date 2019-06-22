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

		static const int SOFTWARE_SERIAL = 0;
		static const int HARDWARE_SERIAL = 1;

		BluetoothClass(int type = BluetoothClass::HARDWARE_SERIAL);

		void BluetoothClass::start() const;
    bool isConnected() const;
		char* getValue() const;
		void sendValue(char * value) const;

	private:

		const int rxPin = 12;
		const int txPin = 11;
		const int statePin = 10;

		static bool type;
		static bool connected;

};

#endif
