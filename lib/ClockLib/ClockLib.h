#ifndef _CARDUINO_CLOCK_LIB_
#define _CARDUINO_CLOCK_LIB_

/**
 * @file ClockLib.h
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

class ClockClass {

	public:

		ClockClass();

		float getTemperature() const;
		void setTime() const;
		DateTime getTime() const;
		char * getFormattedTime() const;

	private:

};

#endif
