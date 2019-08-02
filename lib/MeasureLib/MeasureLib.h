#ifndef _CARDUINO_MEASURE_LIB_
#define _CARDUINO_MEASURE_LIB_

/**
 * @file MeasureLib.h
 * @author Kana (René Lantzsch)
 * @version 1.1
 */

#include <Arduino.h>
#include <Wire.h>

//#include <SparkFunBME280.h>

class MeasureClass {

	public:

		MeasureClass();

    void start() const;
		float getTemperature() const;
		float getHumidity() const;
		float getPressure() const;
		float getAltitude() const;

	private:

};

#endif
