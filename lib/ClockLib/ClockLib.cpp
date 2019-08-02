#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>

#include "ClockLib.h"

/**
 * @file ClockLib.cpp
 * @author Kana (René Lantzsch)
 * @version 1.0
 */

#define DS3231_ADDRESS 0x68

RTC_DS3231 rtc;

ClockClass::ClockClass() {
	rtc.begin();
}

void ClockClass::setTime() const {
	rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
}

DateTime ClockClass::getTime() const {
	DateTime now = rtc.now();

	return now;
}

char *time = malloc(sizeof(char)*9);

char * ClockClass::getFormattedTime() const {
	DateTime now = rtc.now();
	sprintf(time, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

	return time;
}

char *dateStr = malloc(sizeof(char)*7);

char * ClockClass::getLocalDate(int locale) const {
	DateTime now = rtc.now();
	switch(locale) {
		case ClockClass::LOCALE_DE:
			sprintf(dateStr, "%02d.%02d.%02d", now.day(), now.month(), now.year()%100);
			break;
		case ClockClass::LOCALE_SHORT_DE:
			sprintf(dateStr, "%02d.%02d", now.day(), now.month());
			break;
		default:
			sprintf(dateStr, "%02d/%02d/%02d", now.year()%100, now.month(), now.day());
			break;
	}

	return dateStr;
}

float ClockClass::getTemperature() const {
	float temp;
  int msb, lsb;
  Wire.beginTransmission(DS3231_ADDRESS);
  Wire.write(0x11);
  Wire.endTransmission();
  Wire.requestFrom(DS3231_ADDRESS, 2);
  msb = Wire.read();
  lsb = Wire.read();
  temp = ((msb << 2) + (lsb >> 6) ) /4.0;

  return temp;
}
