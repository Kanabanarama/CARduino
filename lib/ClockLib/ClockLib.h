#ifndef _CARDUINO_CLOCK_LIB_
#define _CARDUINO_CLOCK_LIB_

/**
 * @file ClockLib.h
 * @author Kana (René Lantzsch)
 * @version 1.1
 */

#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

class ClockClass {

	public:

		static const int LOCALE_EN = 0;
		static const int LOCALE_DE = 1;

		ClockClass();

		float getTemperature() const;
		void setTime() const;
		DateTime getTime() const;
		char * getFormattedTime() const;
		char * getLocalDate(int locale) const;

	private:

};

#endif
