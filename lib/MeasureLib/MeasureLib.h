#ifndef _CARDUINO_MEASURE_LIB_
#define _CARDUINO_MEASURE_LIB_

/**
 * @file MeasureLib.h
 * @author Kana (René Lantzsch)
 * @version 1.1
 */

#include <Arduino.h>
#include <Wire.h>

#include <dht.h>

class MeasureClass {

	public:

		MeasureClass();

		float getTemperature() const;
		float getHumidity() const;

	private:

};

#endif
