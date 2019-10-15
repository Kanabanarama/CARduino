#ifndef _CARDUINO_CANBUS_LIB_
#define _CARDUINO_CANBUS_LIB_

/**
 * @file CanbusLib.h
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#include <Arduino.h>
#include <Wire.h>

#include "../BluetoothLib/BluetoothLib.h"

class CanbusClass {

	public:

		CanbusClass();

    void start(BluetoothClass output) const;
		float receiveMessage(BluetoothClass output) const;

	private:

};

#endif
